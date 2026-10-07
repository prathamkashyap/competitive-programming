"""
Unit tests for external platform statistics retrieval and parsing.

These tests use static fixtures and do NOT make network calls.
"""

import json
import unittest
from pathlib import Path
from unittest.mock import patch, MagicMock

from scripts.external_stats.models import PlatformStats, RetrievalStatus
from scripts.external_stats.discovery import extract_username_from_url, discover_profiles
from scripts.external_stats.leetcode import _fetch_leetcode_graphql
from scripts.external_stats.hackerrank import (
    _fetch_hackerrank_badges,
    _fetch_hackerrank_skills,
    _fetch_hackerrank_scores,
    _fetch_hackerrank_profile,
    fetch_hackerrank_stats,
)
from scripts.external_stats.hackerearth import _fetch_hackerearth_api, fetch_hackerearth_stats
from scripts.external_stats.geeksforgeeks import _fetch_gfg_practice_api, _fetch_gfg_embedded_state
from scripts.external_stats.codechef import _fetch_codechef_html
from scripts.external_stats.snapshot_loader import get_snapshot_stats


class TestProfileDiscovery(unittest.TestCase):
    """Test URL and username extraction."""

    def test_extract_usernames(self):
        self.assertEqual(
            extract_username_from_url("https://leetcode.com/u/prathamkashyap/", "leetcode"),
            "prathamkashyap"
        )
        self.assertEqual(
            extract_username_from_url("https://codeforces.com/profile/prathamkashyap", "codeforces"),
            "prathamkashyap"
        )
        self.assertEqual(
            extract_username_from_url("https://www.codechef.com/users/prathamkashyap", "codechef"),
            "prathamkashyap"
        )
        self.assertEqual(
            extract_username_from_url("https://www.hackerearth.com/@prathamkashyap/", "hackerearth"),
            "prathamkashyap"
        )
        self.assertEqual(
            extract_username_from_url("https://www.hackerrank.com/profile/prathamkashyap", "hackerrank"),
            "prathamkashyap"
        )
        self.assertEqual(
            extract_username_from_url("https://www.geeksforgeeks.org/profile/prathamkashyap", "geeksforgeeks"),
            "prathamkashyap"
        )

    def test_invalid_urls(self):
        self.assertIsNone(extract_username_from_url("https://example.com", "leetcode"))
        self.assertIsNone(extract_username_from_url("https://github.com/prathamkashyap", "codeforces"))


class TestLeetCodeGraphQL(unittest.TestCase):
    """Test LeetCode GraphQL response parsing."""

    def test_leetcode_graphql_parsing_success(self):
        profile_fixture = {
            "data": {
                "matchedUser": {
                    "username": "testuser",
                    "profile": {"ranking": 195472, "reputation": 10, "solutionCount": 5},
                    "submitStats": {
                        "acSubmissionNum": [
                            {"difficulty": "All", "count": 522, "submissions": 753},
                            {"difficulty": "Easy", "count": 171, "submissions": 257},
                            {"difficulty": "Medium", "count": 279, "submissions": 400},
                            {"difficulty": "Hard", "count": 72, "submissions": 96},
                        ],
                        "totalSubmissionNum": [
                            {"difficulty": "All", "count": 522, "submissions": 858},
                        ],
                    },
                }
            }
        }

        badges_fixture = {
            "data": {
                "matchedUser": {
                    "badges": [
                        {"id": "1", "name": "Annual Badge", "displayName": "100 Days Badge 2026"},
                        {"id": "2", "name": "Study Plan", "displayName": "LeetCode 75"},
                    ],
                    "activeBadge": {"displayName": "100 Days Badge 2026"},
                }
            }
        }

        cal_fixture = {
            "data": {
                "matchedUser": {
                    "userCalendar": {
                        "activeYears": [2025, 2026],
                        "streak": 101,
                        "totalActiveDays": 113,
                    }
                }
            }
        }

        lang_fixture = {
            "data": {
                "matchedUser": {
                    "languageProblemCount": [
                        {"languageName": "C++", "problemsSolved": 498},
                        {"languageName": "Java", "problemsSolved": 46},
                    ]
                }
            }
        }

        def mock_execute(query, variables, timeout=15):
            if "userPublicProfile" in query:
                return profile_fixture
            elif "userBadges" in query:
                return badges_fixture
            elif "userCalendar" in query:
                return cal_fixture
            elif "languageStats" in query:
                return lang_fixture
            return None

        with patch("scripts.external_stats.leetcode._execute_graphql", side_effect=mock_execute):
            stats = _fetch_leetcode_graphql("testuser", "https://leetcode.com/u/testuser/")

        self.assertEqual(stats.status, RetrievalStatus.SUCCESS)
        self.assertEqual(stats.metrics["solved"], 522)
        self.assertEqual(stats.metrics["easy"], 171)
        self.assertEqual(stats.metrics["medium"], 279)
        self.assertEqual(stats.metrics["hard"], 72)
        self.assertEqual(stats.metrics["submissions"], 858)
        self.assertEqual(stats.metrics["acceptance_rate"], 87.8)
        self.assertEqual(stats.metrics["global_rank"], 195472)
        self.assertEqual(stats.metrics["streak_days"], 101)
        self.assertEqual(stats.metrics["badges_count"], 2)
        self.assertEqual(stats.metrics["active_badge"], "100 Days Badge 2026")
        self.assertEqual(stats.metrics["languages"]["C++"], 498)

    def test_leetcode_partial_response(self):
        # Only profile returned, badges/calendar fail
        profile_fixture = {
            "data": {
                "matchedUser": {
                    "username": "partialuser",
                    "profile": {"ranking": 200000},
                    "submitStats": {
                        "acSubmissionNum": [
                            {"difficulty": "All", "count": 10},
                        ],
                    },
                }
            }
        }

        def mock_execute(query, variables, timeout=15):
            if "userPublicProfile" in query:
                return profile_fixture
            return None

        with patch("scripts.external_stats.leetcode._execute_graphql", side_effect=mock_execute):
            stats = _fetch_leetcode_graphql("partialuser", "https://leetcode.com/u/partialuser/")

        self.assertEqual(stats.status, RetrievalStatus.PARTIAL)
        self.assertEqual(stats.metrics["solved"], 10)
        self.assertNotIn("easy", stats.metrics)


class TestHackerRankREST(unittest.TestCase):
    """Test HackerRank official REST response parsing and semantic mapping."""

    def test_hackerrank_badges_semantic_mapping(self):
        badges_fixture = {
            "models": [
                {
                    "badge_name": "Problem Solving",
                    "stars": 6,
                    "solved": 229,
                    "current_points": 9436.56,
                    "hacker_rank": 1931,
                },
                {
                    "badge_name": "Sql",
                    "stars": 5,
                    "solved": 58,
                    "current_points": 1130.0,
                    "hacker_rank": 1,
                },
                {
                    "badge_name": "C++",
                    "stars": 5,
                    "solved": 18,
                    "current_points": 425.0,
                    "hacker_rank": 65854,
                },
            ]
        }

        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = json.dumps(badges_fixture).encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            _fetch_hackerrank_badges("testuser", metrics, errors)

        self.assertEqual(metrics["problem_solving_stars"], 6)
        self.assertEqual(metrics["sql_stars"], 5)
        self.assertEqual(metrics["cpp_stars"], 5)
        self.assertEqual(metrics["sql_rank"], 1)
        self.assertEqual(metrics["problem_solving_rank"], 1931)
        self.assertEqual(metrics["total_stars"], 16)
        self.assertEqual(metrics["total_challenges_solved"], 305)

    def test_hackerrank_skills_parsing(self):
        skills_fixture = ["Algorithm", "Data Structure", "SQL", "Python(Advanced)"]
        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = json.dumps(skills_fixture).encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            _fetch_hackerrank_skills("testuser", metrics, errors)

        self.assertEqual(metrics["verified_skills_count"], 4)
        self.assertIn("Python(Advanced)", metrics["verified_skills"])


class TestHackerEarthAPI(unittest.TestCase):
    """Test HackerEarth public metrics API parsing."""

    def test_hackerearth_metrics_parsing(self):
        metrics_fixture = {
            "solutions_submitted": 214,
            "problem_solved": 175,
            "points": 4300,
            "contest_rating": 0,
        }

        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = json.dumps(metrics_fixture).encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            success = _fetch_hackerearth_api("testuser", metrics, errors)

        self.assertTrue(success)
        self.assertEqual(metrics["points"], 4300)
        self.assertEqual(metrics["solved"], 175)
        self.assertEqual(metrics["submissions"], 214)


class TestGeeksforGeeksParsing(unittest.TestCase):
    """Test GFG practice API and embedded HTML state parsing."""

    def test_gfg_practice_api(self):
        practice_fixture = {
            "status": "success",
            "result": {
                "Basic": {"1": {}, "2": {}},
                "Easy": {"3": {}, "4": {}, "5": {}},
                "Medium": {"6": {}, "7": {}},
                "Hard": {"8": {}},
            },
        }

        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = json.dumps(practice_fixture).encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            _fetch_gfg_practice_api("testuser", metrics, errors)

        self.assertEqual(metrics["solved"], 8)
        self.assertEqual(metrics["basic_solved"], 2)
        self.assertEqual(metrics["easy_solved"], 3)
        self.assertEqual(metrics["medium_solved"], 2)
        self.assertEqual(metrics["hard_solved"], 1)

    def test_gfg_embedded_state(self):
        html_fixture = r'\"score\":424,\"total_problems_solved\":98,\"pod_solved_longest_streak\":28,\"pod_solved_current_streak\":28,\"pod_correct_submissions_count\":28'

        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = html_fixture.encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            _fetch_gfg_embedded_state("testuser", metrics, errors)

        self.assertEqual(metrics["coding_score"], 424)
        self.assertEqual(metrics["longest_streak_days"], 28)
        self.assertEqual(metrics["current_streak_days"], 28)
        self.assertEqual(metrics["potd_solved"], 28)


class TestCodeChefParsing(unittest.TestCase):
    """Test CodeChef embedded Drupal.settings JSON parsing."""

    def test_codechef_drupal_settings(self):
        html_fixture = """
        <html><body>
        <script>
        jQuery.extend(Drupal.settings, {
            "date_versus_rating": {
                "all": [
                    {"rating": "850", "rank": "20000"},
                    {"rating": "922", "rank": "17165"}
                ],
                "dsa_monday": [
                    {"rating": "1067", "rank": "2341"}
                ]
            }
        });
        </script>
        <h3>Total Problems Solved: 630</h3>
        <img alt="Diamond League" src="/league.svg">
        <span class="rating">1&#9733;</span>
        </body></html>
        """

        metrics = {}
        errors = []

        mock_resp = MagicMock()
        mock_resp.read.return_value = html_fixture.encode("utf-8")
        mock_resp.__enter__.return_value = mock_resp

        with patch("urllib.request.urlopen", return_value=mock_resp):
            _fetch_codechef_html("https://www.codechef.com/users/testuser", metrics, errors)

        self.assertEqual(metrics["rating"], 922)
        self.assertEqual(metrics["max_rating"], 922)
        self.assertEqual(metrics["global_rank"], 17165)
        self.assertEqual(metrics["dsa_rating"], 1067)
        self.assertEqual(metrics["dsa_global_rank"], 2341)
        self.assertEqual(metrics["solved"], 630)
        self.assertEqual(metrics["league"], "Diamond League")
        self.assertEqual(metrics["stars"], 1)


class TestSnapshotFallback(unittest.TestCase):
    """Test snapshot fallback functionality."""

    def test_snapshot_loader_metrics(self):
        stats = get_snapshot_stats("geeksforgeeks", "prathamkashyap", "https://www.geeksforgeeks.org/profile/prathamkashyap")
        self.assertIsNotNone(stats)
        self.assertEqual(stats.source_type, "screenshot_snapshot")
        self.assertEqual(stats.metrics["coding_score"], 424)
        self.assertEqual(stats.metrics["solved"], 98)

    def test_snapshot_nonexistent_user(self):
        stats = get_snapshot_stats("geeksforgeeks", "unknown_user", "https://www.geeksforgeeks.org/profile/unknown_user")
        self.assertIsNone(stats)


if __name__ == "__main__":
    unittest.main()
