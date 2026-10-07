"""
HackerRank statistics provider using official public REST endpoints.
"""

import json
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


HACKERRANK_HEADERS = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Accept": "application/json",
}


def fetch_hackerrank_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerRank statistics using official public REST endpoints.
    """
    metrics: Dict[str, Any] = {}
    errors: List[str] = []

    # 1. Fetch skill badges & stars
    _fetch_hackerrank_badges(username, metrics, errors)

    # 2. Fetch verified skills & certificates
    _fetch_hackerrank_skills(username, metrics, errors)

    # 3. Fetch track rankings & scores
    _fetch_hackerrank_scores(username, metrics, errors)

    # 4. Fetch profile details
    _fetch_hackerrank_profile(username, metrics, errors)

    # Determine status
    if "skill_badges" in metrics or "problem_solving_stars" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "; ".join(errors) if errors else "Retrieved partial HackerRank statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "; ".join(errors) if errors else "Could not retrieve statistics from HackerRank REST API"

    return PlatformStats(
        platform="HackerRank",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="official_rest_api",
        source_type="live",
        retrieval_method="rest_api",
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_hackerrank_badges(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch domain skill badges, star ratings, and challenge counts."""
    url = f"https://www.hackerrank.com/rest/hackers/{username}/badges"
    headers = dict(HACKERRANK_HEADERS)
    headers["Referer"] = f"https://www.hackerrank.com/profile/{username}"

    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            models = data.get("models", [])
            skill_badges: Dict[str, Any] = {}
            total_solved = 0
            total_stars = 0

            for b in models:
                badge_name = b.get("badge_name")
                stars = b.get("stars", 0)
                solved = b.get("solved", 0)
                points = b.get("current_points")
                rank = b.get("hacker_rank")

                if badge_name:
                    badge_info = {
                        "stars": stars,
                        "solved": solved,
                    }
                    if points is not None:
                        badge_info["points"] = points
                    if rank is not None:
                        badge_info["rank"] = rank

                    skill_badges[badge_name] = badge_info
                    total_solved += solved
                    total_stars += stars

                    # Specific field mappings
                    norm_name = badge_name.lower().replace(" ", "_").replace("++", "pp")
                    if norm_name in ["problem_solving", "cpp", "java", "python", "sql"]:
                        metrics[f"{norm_name}_stars"] = stars

            if skill_badges:
                metrics["skill_badges"] = skill_badges
                metrics["badges_count"] = len(skill_badges)
                metrics["total_stars"] = total_stars
                metrics["total_challenges_solved"] = total_solved

            # Extract specific high-value ranks
            if "Sql" in skill_badges and skill_badges["Sql"].get("rank"):
                metrics["sql_rank"] = skill_badges["Sql"]["rank"]
            if "Problem Solving" in skill_badges and skill_badges["Problem Solving"].get("rank"):
                metrics["problem_solving_rank"] = skill_badges["Problem Solving"]["rank"]

    except Exception as e:
        errors.append(f"Badges REST API error: {str(e)}")


def _fetch_hackerrank_skills(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch verified skills list."""
    url = f"https://www.hackerrank.com/rest/hackers/{username}/skills"
    headers = dict(HACKERRANK_HEADERS)
    headers["Referer"] = f"https://www.hackerrank.com/profile/{username}"

    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            skills = json.loads(resp.read().decode("utf-8"))
            if isinstance(skills, list) and skills:
                metrics["verified_skills"] = skills
                metrics["verified_skills_count"] = len(skills)
    except Exception as e:
        errors.append(f"Skills REST API error: {str(e)}")


def _fetch_hackerrank_scores(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch track scores and ranks from scores_elo."""
    url = f"https://www.hackerrank.com/rest/hackers/{username}/scores_elo"
    headers = dict(HACKERRANK_HEADERS)
    headers["Referer"] = f"https://www.hackerrank.com/profile/{username}"

    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            tracks = json.loads(resp.read().decode("utf-8"))
            if isinstance(tracks, list):
                track_ranks = {}
                for t in tracks:
                    name = t.get("name")
                    practice = t.get("practice") or {}
                    rank = practice.get("rank")
                    score = practice.get("score")
                    if name and rank and rank != "N/A" and score and score > 0:
                        track_ranks[name] = {"rank": rank, "score": score}
                if track_ranks:
                    metrics["track_ranks"] = track_ranks
    except Exception as e:
        errors.append(f"Scores ELO API error: {str(e)}")


def _fetch_hackerrank_profile(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch user profile metadata."""
    url = f"https://www.hackerrank.com/rest/contests/master/hackers/{username}/profile"
    headers = dict(HACKERRANK_HEADERS)
    headers["Referer"] = f"https://www.hackerrank.com/profile/{username}"

    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            model = data.get("model") or {}
            if model.get("country"):
                metrics["country"] = model["country"]
            if model.get("level") is not None:
                metrics["level"] = model["level"]
            if model.get("created_at"):
                metrics["member_since"] = model["created_at"][:10]
    except Exception as e:
        errors.append(f"Profile API error: {str(e)}")
