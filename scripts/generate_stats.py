#!/usr/bin/env python3
"""
Repository Statistics Generator

This script scans the competitive-programming repository and generates
statistics about solution files, templates, and notes.

Generated output is deterministic and requires no external APIs or network access.
"""

import os
import json
from pathlib import Path
from collections import defaultdict
from typing import Dict, List, Tuple


# Configuration
REPO_ROOT = Path(__file__).parent.parent
PLATFORM_DIRS = {
    'codeforces',
    'leetcode',
    'codechef',
    'cses',
    'atcoder',
    'hackerearth',
    'hackerrank',
    'geeksforgeeks',
}
IGNORE_DIRS = {
    '.git',
    'assets',
    'badges',
    'docs',
    'scripts',
    '__pycache__',
    '.vscode',
    '.cph',
    'node_modules',
    'venv',
    '.venv',
    'env',
}
CODE_EXTENSIONS = {
    '.cpp',
    '.cc',
    '.cxx',
    '.py',
    '.java',
}
DOC_EXTENSIONS = {
    '.md',
    '.txt',
}


def is_code_file(filepath: Path) -> bool:
    """Check if a file is a code file based on extension."""
    return filepath.suffix.lower() in CODE_EXTENSIONS


def is_doc_file(filepath: Path) -> bool:
    """Check if a file is a documentation file."""
    return filepath.suffix.lower() in DOC_EXTENSIONS


def should_ignore_dir(dirpath: Path) -> bool:
    """Check if a directory should be ignored."""
    return dirpath.name in IGNORE_DIRS or dirpath.name.startswith('.')


def categorize_file(filepath: Path) -> str:
    """
    Categorize a file based on its path.
    Returns: 'solution', 'template', 'note', or 'other'
    """
    parts = filepath.parts

    # Templates
    if 'templates' in parts:
        return 'template'

    # Notes
    if 'notes' in parts:
        return 'note'

    # Platform solutions
    for platform in PLATFORM_DIRS:
        if platform in parts:
            return 'solution'

    return 'other'


def scan_repository() -> Dict:
    """
    Scan the repository and collect statistics.
    Returns a dictionary with all collected data.
    """
    stats = {
        'total_files': 0,
        'by_language': defaultdict(int),
        'by_platform': defaultdict(int),
        'by_category': defaultdict(int),
        'by_extension': defaultdict(int),
        'solutions': [],
        'templates': [],
        'notes': [],
    }

    for root, dirs, files in os.walk(REPO_ROOT):
        root_path = Path(root)

        # Filter ignored directories
        dirs[:] = [d for d in dirs if not should_ignore_dir(root_path / d)]

        for filename in files:
            filepath = root_path / filename
            rel_path = filepath.relative_to(REPO_ROOT)

            # Skip if not a code file
            if not is_code_file(filepath):
                continue

            stats['total_files'] += 1
            stats['by_extension'][filepath.suffix.lower()] += 1

            # Determine language
            ext = filepath.suffix.lower()
            if ext in {'.cpp', '.cc', '.cxx'}:
                lang = 'C++'
            elif ext == '.py':
                lang = 'Python'
            elif ext == '.java':
                lang = 'Java'
            else:
                lang = 'Other'
            stats['by_language'][lang] += 1

            # Categorize file
            category = categorize_file(rel_path)
            stats['by_category'][category] += 1

            # Collect by platform
            for platform in PLATFORM_DIRS:
                if platform in rel_path.parts:
                    stats['by_platform'][platform] += 1
                    break

            # Store file info for detailed output
            file_info = {
                'path': str(rel_path),
                'language': lang,
                'extension': ext,
            }

            if category == 'solution':
                stats['solutions'].append(file_info)
            elif category == 'template':
                stats['templates'].append(file_info)
            elif category == 'note':
                stats['notes'].append(file_info)

    # Convert defaultdicts to regular dicts for JSON serialization
    stats['by_language'] = dict(stats['by_language'])
    stats['by_platform'] = dict(stats['by_platform'])
    stats['by_category'] = dict(stats['by_category'])
    stats['by_extension'] = dict(stats['by_extension'])

    # Sort solution lists for deterministic output
    stats['solutions'].sort(key=lambda x: x['path'])
    stats['templates'].sort(key=lambda x: x['path'])
    stats['notes'].sort(key=lambda x: x['path'])

    return stats


def extract_codeforces_rating(filepath: Path) -> str:
    """
    Extract Codeforces rating from directory structure if present.
    Returns the rating as a string, or 'unrated' if not found.
    """
    parts = filepath.parts
    for part in parts:
        if part.isdigit():
            return part
    return 'unrated'


def generate_problem_index(stats: Dict) -> List[Dict]:
    """
    Generate a problem index from the solution files.
    Each entry contains platform, path, filename, language, and rating (if available).
    """
    problem_index = []

    for solution in stats['solutions']:
        filepath = Path(solution['path'])
        parts = filepath.parts

        # Determine platform
        platform = 'unknown'
        for p in PLATFORM_DIRS:
            if p in parts:
                platform = p
                break

        # Extract Codeforces rating if applicable
        rating = None
        if platform == 'codeforces':
            rating = extract_codeforces_rating(filepath)

        entry = {
            'platform': platform,
            'path': str(filepath),
            'filename': filepath.name,
            'language': solution['language'],
        }

        if rating:
            entry['rating'] = rating

        problem_index.append(entry)

    # Sort deterministically
    problem_index.sort(key=lambda x: (x['platform'], x['path']))

    return problem_index


def generate_stats_markdown(stats: Dict) -> str:
    """Generate a markdown document with repository statistics."""
    lines = [
        "# Repository Statistics",
        "",
        "<!--",
        "This file is automatically generated by scripts/generate_stats.py.",
        "Do not edit this file manually.",
        "To update statistics, run: python scripts/generate_stats.py",
        "-->",
        "",
        "## Overview",
        "",
        f"- **Total code files**: {stats['total_files']}",
        "",
        "## Language Breakdown",
        "",
        "| Language | Count |",
        "|----------|-------|",
    ]

    for lang in sorted(stats['by_language'].keys()):
        lines.append(f"| {lang} | {stats['by_language'][lang]} |")

    lines.extend([
        "",
        "## Platform Breakdown",
        "",
        "| Platform | Solution Count |",
        "|----------|----------------|",
    ])

    for platform in sorted(stats['by_platform'].keys()):
        lines.append(f"| {platform.capitalize()} | {stats['by_platform'][platform]} |")

    lines.extend([
        "",
        "## Category Breakdown",
        "",
        "| Category | Count |",
        "|----------|-------|",
    ])

    for category in ['solution', 'template', 'note']:
        count = stats['by_category'].get(category, 0)
        lines.append(f"| {category.capitalize()} | {count} |")

    lines.extend([
        "",
        "## File Extension Breakdown",
        "",
        "| Extension | Count |",
        "|-----------|-------|",
    ])

    for ext in sorted(stats['by_extension'].keys()):
        lines.append(f"| {ext} | {stats['by_extension'][ext]} |")

    lines.append("")
    return "\n".join(lines)


def generate_problem_index_markdown(problem_index: List[Dict]) -> str:
    """Generate a markdown document with the problem index."""
    lines = [
        "# Problem Index",
        "",
        "<!--",
        "This file is automatically generated by scripts/generate_stats.py.",
        "Do not edit this file manually.",
        "To update the index, run: python scripts/generate_stats.py",
        "-->",
        "",
        "This index lists all solution files in the repository.",
        "",
        "| Platform | Path | Filename | Language | Rating |",
        "|----------|------|----------|----------|--------|",
    ]

    for entry in problem_index:
        platform = entry['platform'].capitalize()
        path = entry['path']
        filename = entry['filename']
        language = entry['language']
        rating = entry.get('rating', 'N/A')
        lines.append(f"| {platform} | `{path}` | {filename} | {language} | {rating} |")

    lines.append("")
    return "\n".join(lines)


def main():
    """Main entry point."""
    print("Scanning repository...")
    stats = scan_repository()

    print(f"Found {stats['total_files']} code files")

    # Generate problem index
    problem_index = generate_problem_index(stats)
    print(f"Generated index with {len(problem_index)} solutions")

    # Write stats markdown
    stats_md = generate_stats_markdown(stats)
    stats_path = REPO_ROOT / 'docs' / 'generated' / 'stats.md'
    stats_path.parent.mkdir(parents=True, exist_ok=True)
    stats_path.write_text(stats_md)
    print(f"Written statistics to {stats_path}")

    # Write problem index markdown
    index_md = generate_problem_index_markdown(problem_index)
    index_path = REPO_ROOT / 'docs' / 'generated' / 'problem-index.md'
    index_path.write_text(index_md)
    print(f"Written problem index to {index_path}")

    # Optionally write JSON for programmatic access
    json_path = REPO_ROOT / 'docs' / 'generated' / 'stats.json'
    json_path.write_text(json.dumps(stats, indent=2))
    print(f"Written JSON statistics to {json_path}")

    print("\nGeneration complete!")


if __name__ == '__main__':
    main()
