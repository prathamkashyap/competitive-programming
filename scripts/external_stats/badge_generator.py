"""
Pure Python SVG badge generator for competitive programming statistics.

Generates clean, modern SVG badges without external dependencies.
"""

from pathlib import Path
from typing import Dict, Any
from datetime import datetime, timezone


def generate_svg_badge(
    label: str,
    value: str,
    color: str = "#0066cc",
    label_color: str = "#555555",
    value_color: str = "#ffffff",
    width: int = None,
    filename: str = None,
) -> str:
    """
    Generate an SVG badge with a label and value.

    Args:
        label: Left side text (e.g., "Codeforces")
        value: Right side text (e.g., "815 (newbie)")
        color: Background color of the value section
        label_color: Text color of the label section
        value_color: Text color of the value section
        width: Total width (auto-calculated if None)
        filename: If provided, saves to this path

    Returns:
        SVG string
    """
    # Text widths (approximate, monospace-ish)
    label_width = len(label) * 7 + 10
    value_width = len(value) * 7 + 10
    total_width = width or (label_width + value_width)
    height = 20

    svg = f"""<svg xmlns="http://www.w3.org/2000/svg" width="{total_width}" height="{height}">
  <rect x="0" y="0" width="{label_width}" height="{height}" fill="#f0f0f0" rx="3" ry="3"/>
  <rect x="{label_width}" y="0" width="{value_width}" height="{height}" fill="{color}" rx="3" ry="3"/>
  <rect x="{label_width - 3}" y="0" width="3" height="{height}" fill="#f0f0f0"/>
  <text x="{label_width // 2}" y="14" font-family="Arial, sans-serif" font-size="11" font-weight="bold" fill="{label_color}" text-anchor="middle">{label}</text>
  <text x="{label_width + value_width // 2}" y="14" font-family="Arial, sans-serif" font-size="11" font-weight="bold" fill="{value_color}" text-anchor="middle">{value}</text>
</svg>"""

    if filename:
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        Path(filename).write_text(svg, encoding="utf-8")

    return svg


def generate_codeforces_badge(rating: int, output_dir: Path, rank: str = None) -> str:
    """Generate Codeforces rating badge."""
    color = "#FF0000" if rating >= 2400 else "#FF8C00" if rating >= 2100 else "#03A89E" if rating >= 1900 else "#4169E1" if rating >= 1600 else "#7F00FF" if rating >= 1400 else "#2E8B57" if rating >= 1200 else "#AA00AA" if rating >= 1000 else "#808080"
    if rank:
        value = f"{rating} ({rank})"
    else:
        value = f"{rating}"
    return generate_svg_badge(
        label="Codeforces",
        value=value,
        color=color,
        filename=output_dir / "codeforces-rating.svg"
    )


def generate_leetcode_badge(total: int, output_dir: Path, easy: int = None, medium: int = None, hard: int = None) -> str:
    """Generate LeetCode solved badge."""
    if easy is not None and medium is not None and hard is not None:
        value = f"{total} ({easy}E/{medium}M/{hard}H)"
    else:
        value = f"{total} solved"
    return generate_svg_badge(
        label="LeetCode",
        value=value,
        color="#FFA116",
        filename=output_dir / "leetcode-solved.svg"
    )


def generate_codechef_badge(rating: int, output_dir: Path, stars: int = None) -> str:
    """Generate CodeChef rating badge."""
    color = "#FF0000" if rating >= 2800 else "#FF6600" if rating >= 2400 else "#FF9900" if rating >= 2000 else "#FFCC00" if rating >= 1600 else "#99CC00" if rating >= 1400 else "#00CC00" if rating >= 1200 else "#6699FF" if rating >= 1000 else "#666666"
    if stars is not None:
        value = f"{rating} ({stars}★)"
    else:
        value = f"{rating}"
    return generate_svg_badge(
        label="CodeChef",
        value=value,
        color=color,
        filename=output_dir / "codechef-rating.svg"
    )


def generate_repo_badge(total_solutions: int, output_dir: Path) -> str:
    """Generate repository solutions count badge."""
    return generate_svg_badge(
        label="Solutions",
        value=str(total_solutions),
        color="#0066cc",
        filename=output_dir / "repo-solutions.svg"
    )


def generate_all_badges(
    external_stats: list,
    repo_stats: Dict[str, Any],
    output_dir: Path,
) -> Dict[str, str]:
    """
    Generate all badges from external and repository statistics.

    Args:
        external_stats: List of PlatformStats from external_stats.py
        repo_stats: Repository statistics dict from generate_stats.py
        output_dir: Directory to save badge SVGs

    Returns:
        Dict mapping badge name to relative path
    """
    badge_paths = {}
    output_dir.mkdir(parents=True, exist_ok=True)

    # Extract platform stats
    cf_stats = next((s for s in external_stats if s["platform"] == "Codeforces"), None)
    lc_stats = next((s for s in external_stats if s["platform"] == "LeetCode"), None)
    cc_stats = next((s for s in external_stats if s["platform"] == "CodeChef"), None)

    # Codeforces badge
    if cf_stats and cf_stats.get("status") == "success":
        metrics = cf_stats.get("metrics", {})
        rating = metrics.get("rating")
        rank = metrics.get("rank")
        if rating:
            generate_codeforces_badge(rating, output_dir, rank)
            badge_paths["codeforces"] = "docs/generated/badges/codeforces-rating.svg"

    # LeetCode badge
    if lc_stats and lc_stats.get("status") == "success":
        metrics = lc_stats.get("metrics", {})
        total = metrics.get("solved")
        easy = metrics.get("easy")
        medium = metrics.get("medium")
        hard = metrics.get("hard")
        if total:
            generate_leetcode_badge(total, output_dir, easy, medium, hard)
            badge_paths["leetcode"] = "docs/generated/badges/leetcode-solved.svg"

    # CodeChef badge
    if cc_stats and cc_stats.get("status") == "success":
        metrics = cc_stats.get("metrics", {})
        rating = metrics.get("rating")
        stars = metrics.get("stars")
        if rating:
            generate_codechef_badge(rating, output_dir, stars)
            badge_paths["codechef"] = "docs/generated/badges/codechef-rating.svg"

    # Repository badge
    total_solutions = repo_stats.get("by_category", {}).get("solution", 0)
    if total_solutions > 0:
        generate_repo_badge(total_solutions, output_dir)
        badge_paths["repo"] = "docs/generated/badges/repo-solutions.svg"

    return badge_paths
