#!/usr/bin/env python3
"""
Repository Statistics Generator

This script scans the competitive-programming repository and generates
statistics about solution files, templates, and notes.

Generated output is deterministic and requires no external APIs or network access.
"""

import os
import json
import re
from pathlib import Path
from collections import defaultdict
from typing import Dict, List, Tuple, Optional
from datetime import datetime, timezone


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
    'tests',
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


def extract_codeforces_rating(filepath: Path) -> Optional[str]:
    """
    Extract Codeforces rating from directory structure if present.
    Returns the rating as a string, or None if not found.
    """
    parts = filepath.parts
    for part in parts:
        if part.isdigit():
            return part
    return None


def extract_problem_code(filepath: Path, platform: str) -> Optional[str]:
    """
    Extract problem code from filename (e.g., "1701C.cpp" -> "1701C", "1701C_Title.cpp" -> "1701C").
    Returns None if pattern doesn't match.
    """
    filename = filepath.stem  # filename without extension
    if platform == "codeforces":
        # Codeforces pattern: contestId_problemIndex (e.g., 1701C, 1348B)
        # May be followed by underscore and title: 1701C_Title.cpp
        # Problem index is typically uppercase letter (A-Z) or (A-Z)(a-z)
        match = re.match(r'^(\d+[A-Z][a-z]?)(?:_.*)?$', filename)
        if match:
            return match.group(1)
    # For other platforms, we can't reliably extract codes without more context
    return None


def extract_problem_title(filepath: Path) -> Optional[str]:
    """
    Extract problem title from file header if present.
    Returns None if not found.
    """
    try:
        content = filepath.read_text(encoding='utf-8', errors='ignore')
        # Look for common title patterns in comments
        patterns = [
            r'//\s*Title:\s*(.+)',
            r'/\*\*\s*Title:\s*(.+)',
            r'#\s*Title:\s*(.+)',
            r'//\s*Problem:\s*(.+)',
        ]
        for pattern in patterns:
            match = re.search(pattern, content, re.IGNORECASE)
            if match:
                title = match.group(1).strip()
                # Remove trailing comment markers
                title = re.sub(r'\s*\*/\s*$', '', title)
                return title if title else None
    except Exception:
        pass
    return None


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
            rating_str = extract_codeforces_rating(filepath)
            if rating_str:
                rating = int(rating_str)

        # Extract problem code if applicable
        code = extract_problem_code(filepath, platform)

        # Extract title from file header
        title = extract_problem_title(filepath)

        # Normalize language to lowercase short form
        lang = solution['language'].lower()
        if lang == 'c++':
            lang = 'cpp'

        entry = {
            'platform': platform,
            'path': str(filepath),
            'filename': filepath.name,
            'language': lang,
        }

        if rating is not None:
            entry['rating'] = rating
        if code:
            entry['code'] = code
        if title:
            entry['title'] = title
        # Tags empty for now - can be added later if a tagging system is implemented
        entry['tags'] = []

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


def generate_problem_index_json(problem_index: List[Dict]) -> Dict:
    """
    Generate a structured JSON document with the problem index.

    Schema:
    {
        "generated_at": "<ISO timestamp>",
        "total_problems": <count>,
        "problems": [
            {
                "platform": "codeforces",
                "code": "1701C",
                "title": "",
                "rating": 1400,
                "path": "codeforces/1400/1701C.cpp",
                "language": "cpp",
                "tags": []
            }
        ]
    }
    """
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "total_problems": len(problem_index),
        "problems": problem_index,
    }


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

    # Write problem index JSON
    index_json = generate_problem_index_json(problem_index)
    index_json_path = REPO_ROOT / 'docs' / 'generated' / 'problem-index.json'
    index_json_path.write_text(json.dumps(index_json, indent=2))
    print(f"Written problem index JSON to {index_json_path}")

    # Write repository stats JSON
    json_path = REPO_ROOT / 'docs' / 'generated' / 'stats.json'
    json_path.write_text(json.dumps(stats, indent=2))
    print(f"Written JSON statistics to {json_path}")

    print("\nGeneration complete!")


if __name__ == '__main__':
    main()
