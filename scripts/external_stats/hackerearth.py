"""
HackerEarth statistics provider using public REST API and browser rendering.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


HACKEREARTH_HEADERS = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Accept": "application/json, text/plain, */*",
}


def fetch_hackerearth_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerEarth statistics using public endpoints and browser rendering fallback.
    """
    metrics: Dict[str, Any] = {}
    errors: List[str] = []

    # 1. Primary: Fetch from public JSON API
    api_success = _fetch_hackerearth_api(username, metrics, errors)

    # 2. Supplementary / Browser inspection: Get track rankings & stars
    try:
        from .browser_renderer import is_playwright_available
        if is_playwright_available():
            _fetch_hackerearth_browser(username, profile_url, metrics)
    except Exception:
        pass

    # Determine status
    if "points" in metrics and "solved" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "; ".join(errors) if errors else "Retrieved partial HackerEarth statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "; ".join(errors) if errors else "Could not retrieve statistics from HackerEarth"

    retrieval_method = "api_and_rendered" if ("basic_programming_rank" in metrics or "top_percentiles" in metrics) else "public_api"

    return PlatformStats(
        platform="HackerEarth",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="public_api",
        source_type="live",
        retrieval_method=retrieval_method,
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_hackerearth_api(username: str, metrics: Dict[str, Any], errors: List[str]) -> bool:
    """Fetch metrics and badges from HackerEarth's public community API."""
    headers = dict(HACKEREARTH_HEADERS)
    headers["Referer"] = f"https://www.hackerearth.com/@{username}/"

    # Metrics endpoint
    metrics_url = f"https://www.hackerearth.com/api/community/user/profile/{username}/metrics/"
    try:
        req = urllib.request.Request(metrics_url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            if "points" in data:
                metrics["points"] = data["points"]
            if "problem_solved" in data:
                metrics["solved"] = data["problem_solved"]
            if "solutions_submitted" in data:
                metrics["submissions"] = data["solutions_submitted"]
            if "contest_rating" in data:
                metrics["contest_rating"] = data["contest_rating"]
    except Exception as e:
        errors.append(f"Metrics API error: {str(e)}")

    # Badges endpoint
    badges_url = f"https://www.hackerearth.com/api/community/user/profile/{username}/badges/"
    try:
        req = urllib.request.Request(badges_url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            badges_list = []
            if isinstance(data, list):
                for category_item in data:
                    for b_entry in category_item.get("badges", []):
                        badge_obj = b_entry.get("badge", {})
                        b_name = badge_obj.get("name")
                        if b_name and b_name not in badges_list:
                            badges_list.append(b_name)
            if badges_list:
                metrics["badges"] = badges_list
                metrics["badges_count"] = len(badges_list)
    except Exception as e:
        errors.append(f"Badges API error: {str(e)}")

    return "points" in metrics or "solved" in metrics


def _parse_hackerearth_tracks(html: str, text: str) -> Dict[str, Any]:
    """
    Parse track leaderboard rankings and points with strict structural verification
    and validation, avoiding fragile positional regex assumptions.
    """
    extracted: Dict[str, Any] = {}

    # 1. Structured table extraction from HTML if present
    tables = re.findall(r"<table[^>]*>(.*?)</table>", html, re.DOTALL | re.IGNORECASE)
    for table_html in tables:
        headers = [re.sub(r"<[^>]+>", "", h).strip().lower() for h in re.findall(r"<th[^>]*>(.*?)</th>", table_html, re.DOTALL | re.IGNORECASE)]
        rank_idx = -1
        points_idx = -1
        for idx, h in enumerate(headers):
            if "rank" in h:
                rank_idx = idx
            elif "point" in h or "score" in h:
                points_idx = idx

        if rank_idx != -1 and points_idx != -1:
            rows = re.findall(r"<tr[^>]*>(.*?)</tr>", table_html, re.DOTALL | re.IGNORECASE)
            for row in rows:
                cols = [re.sub(r"<[^>]+>", "", c).strip() for c in re.findall(r"<td[^>]*>(.*?)</td>", row, re.DOTALL | re.IGNORECASE)]
                if len(cols) > max(rank_idx, points_idx):
                    row_content = " ".join(cols).lower()
                    track_key = None
                    if "basic programming" in row_content:
                        track_key = "basic_programming"
                    elif "algorithms" in row_content:
                        track_key = "algorithms"

                    if track_key:
                        try:
                            rank_digits = re.sub(r"[^\d]", "", cols[rank_idx])
                            points_digits = re.sub(r"[^\d]", "", cols[points_idx])
                            if rank_digits and points_digits:
                                r_val = int(rank_digits)
                                p_val = int(points_digits)
                                if 1 <= r_val <= 10_000_000 and 0 <= p_val <= 100_000:
                                    extracted[f"{track_key}_rank"] = r_val
                                    extracted[f"{track_key}_points"] = p_val
                        except (ValueError, IndexError):
                            pass

    # 2. Text-based extraction with verified header order and bounds validation
    tracks = [
        ("Basic Programming", "basic_programming"),
        ("Algorithms", "algorithms"),
    ]

    for label, track_key in tracks:
        if f"{track_key}_rank" in extracted:
            continue

        label_pos = text.find(label)
        if label_pos == -1:
            continue

        window_start = max(0, label_pos - 500)
        preceding_text = text[window_start:label_pos]

        header_match_rank_first = re.search(r"(topic|track)[\s\S]{1,50}?(rank)[\s\S]{1,50}?(points|score)", preceding_text, re.IGNORECASE)
        header_match_pts_first = re.search(r"(topic|track)[\s\S]{1,50}?(points|score)[\s\S]{1,50}?(rank)", preceding_text, re.IGNORECASE)

        rank_first = None
        if header_match_rank_first:
            rank_first = True
        elif header_match_pts_first:
            rank_first = False

        if rank_first is None:
            # Header order cannot be verified; fail safely to prevent incorrect metric assignment
            continue

        line_chunk = text[label_pos:label_pos + 120]
        m = re.search(rf"{re.escape(label)}\s*(\d+)\s*(\d+)", line_chunk, re.IGNORECASE)
        if m:
            try:
                v1, v2 = int(m.group(1)), int(m.group(2))
                r_val = v1 if rank_first else v2
                p_val = v2 if rank_first else v1
                if 1 <= r_val <= 10_000_000 and 0 <= p_val <= 100_000:
                    extracted[f"{track_key}_rank"] = r_val
                    extracted[f"{track_key}_points"] = p_val
            except ValueError:
                pass

    return extracted


def _fetch_hackerearth_browser(username: str, profile_url: str, metrics: Dict[str, Any]):
    """Use browser rendering to supplement track rankings, top percentiles, and star levels."""
    import asyncio
    from .browser_renderer import fetch_rendered_page

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_timeout=20000,
            capture_network=False,
        )
        text = page_data.get("text", "")
        html = page_data.get("html", "")
        if not text and not html:
            return

        # Top percentiles
        top_list = []
        for line in text.split("\n"):
            line = line.strip()
            m = re.match(r"^Top\s*(\d+%)\s*in\s*([A-Za-z\s]+)$", line)
            if m:
                top_list.append(f"Top {m.group(1)} in {m.group(2).strip()}")
        if top_list:
            metrics["top_percentiles"] = sorted(list(set(top_list)))

        # Track rankings and points with verified structural parsing and bounds
        track_metrics = _parse_hackerearth_tracks(html, text)
        metrics.update(track_metrics)

        # Submissions in last year
        subs_match = re.search(r"(\d+)\s*in the last year", text)
        if subs_match:
            try:
                metrics["submissions_last_year"] = int(subs_match.group(1))
            except ValueError:
                pass

    try:
        asyncio.run(_fetch())
    except Exception:
        pass
