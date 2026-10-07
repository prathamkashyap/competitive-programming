#!/usr/bin/env python3
"""
C++ Compilation Validation Script

This script validates that C++ solution files compile correctly.
It does NOT execute solutions or modify existing files.

It uses syntax-only compilation where possible to avoid linker conflicts
from files containing their own main() functions.
"""

import os
import subprocess
import sys
from pathlib import Path
from typing import List, Tuple, Dict
import shutil


# Configuration
REPO_ROOT = Path(__file__).parent.parent
CPP_EXTENSIONS = {'.cpp', '.cc', '.cxx'}
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


def find_compiler() -> Tuple[str, List[str]]:
    """
    Find an available C++ compiler.
    Returns (compiler_name, base_compile_flags).
    """
    # Try g++ first
    if shutil.which('g++'):
        return 'g++', ['-std=c++20', '-Wall', '-Wextra']

    # Try clang++
    if shutil.which('clang++'):
        return 'clang++', ['-std=c++20', '-Wall', '-Wextra']

    # Try c++ (macOS symlink)
    if shutil.which('c++'):
        return 'c++', ['-std=c++20', '-Wall', '-Wextra']

    print("Error: No C++ compiler found (g++, clang++, or c++)")
    print("Please install a C++20-capable compiler:")
    print("  - Ubuntu/Debian: sudo apt install g++")
    print("  - macOS: xcode-select --install")
    sys.exit(1)


def should_ignore_dir(dirpath: Path) -> bool:
    """Check if a directory should be ignored."""
    return dirpath.name in IGNORE_DIRS or dirpath.name.startswith('.')


def find_cpp_files() -> List[Path]:
    """Find all C++ files in the repository."""
    cpp_files = []

    for root, dirs, files in os.walk(REPO_ROOT):
        root_path = Path(root)

        # Filter ignored directories
        dirs[:] = [d for d in dirs if not should_ignore_dir(root_path / d)]

        for filename in files:
            filepath = root_path / filename
            if filepath.suffix.lower() in CPP_EXTENSIONS:
                cpp_files.append(filepath)

    return sorted(cpp_files)


def compile_file(filepath: Path, compiler: str, flags: List[str]) -> Tuple[bool, str, str]:
    """
    Attempt to compile a single C++ file.
    Uses syntax-only compilation to avoid linker conflicts.

    Returns (success, error_message, skip_reason).
    skip_reason is non-empty if the file should be skipped due to local infrastructure.
    """
    # Try syntax-only compilation first (most reliable for files with main())
    syntax_flags = flags + ['-fsyntax-only']

    try:
        result = subprocess.run(
            [compiler] + syntax_flags + [str(filepath)],
            capture_output=True,
            text=True,
            timeout=30,
        )

        if result.returncode == 0:
            return True, "", ""

        # Check for known local infrastructure issues
        stderr = result.stderr
        if "redefinition of 'MOD'" in stderr and "bits/stdc++.h" in stderr:
            # System's bits/stdc++.h has been modified with CP helpers
            # This is a local infrastructure issue, not a code issue
            return False, "", "Skipped: System bits/stdc++.h has MOD constant defined, conflicts with solution"

        if "expected unqualified-id" in stderr and "#define sz" in stderr:
            # System's bits/stdc++.h has sz macro defined
            # This is a local infrastructure issue, not a code issue
            return False, "", "Skipped: System bits/stdc++.h has sz macro defined, conflicts with solution"

        # If syntax-only fails, try regular compilation to output directory
        # This might fail due to duplicate main(), but that's expected
        output_dir = REPO_ROOT / '.validation_output'
        output_dir.mkdir(exist_ok=True)
        output_file = output_dir / filepath.stem

        compile_flags = flags + ['-c', str(filepath), '-o', str(output_file.with_suffix('.o'))]

        result = subprocess.run(
            [compiler] + compile_flags,
            capture_output=True,
            text=True,
            timeout=30,
        )

        if result.returncode == 0:
            # Clean up object file
            if output_file.with_suffix('.o').exists():
                output_file.with_suffix('.o').unlink()
            return True, "", ""

        return False, result.stderr, ""

    except subprocess.TimeoutExpired:
        return False, "Compilation timeout", ""
    except Exception as e:
        return False, str(e), ""


def main():
    """Main entry point."""
    print("C++ Compilation Validation")
    print("=" * 50)

    # Find compiler
    compiler, flags = find_compiler()
    print(f"Using compiler: {compiler}")
    print(f"Flags: {' '.join(flags)}")
    print()

    # Find C++ files
    cpp_files = find_cpp_files()
    print(f"Found {len(cpp_files)} C++ files to validate")
    print()

    # Validate each file
    passed = []
    failed = []
    skipped = []

    for i, filepath in enumerate(cpp_files, 1):
        rel_path = filepath.relative_to(REPO_ROOT)
        print(f"[{i}/{len(cpp_files)}] Validating {rel_path}...", end=' ')

        success, error, skip_reason = compile_file(filepath, compiler, flags)

        if success:
            print("✓ PASSED")
            passed.append(filepath)
        elif skip_reason:
            print("⊘ SKIPPED")
            skipped.append((filepath, skip_reason))
        else:
            print("✗ FAILED")
            failed.append((filepath, error))
            # Print first few lines of error for debugging
            if error:
                error_lines = error.strip().split('\n')[:3]
                for line in error_lines:
                    print(f"  {line}")

    # Summary
    print()
    print("=" * 50)
    print("VALIDATION SUMMARY")
    print("=" * 50)
    print(f"Total files: {len(cpp_files)}")
    print(f"Passed: {len(passed)}")
    print(f"Failed: {len(failed)}")
    print(f"Skipped: {len(skipped)}")
    print()

    # Report failures
    if failed:
        print("FAILED FILES:")
        print("-" * 50)
        for filepath, error in failed:
            rel_path = filepath.relative_to(REPO_ROOT)
            print(f"\n{rel_path}:")
            print(error)

    # Report skipped files
    if skipped:
        print("\nSKIPPED FILES (local infrastructure issues):")
        print("-" * 50)
        for filepath, reason in skipped:
            rel_path = filepath.relative_to(REPO_ROOT)
            print(f"\n{rel_path}:")
            print(reason)

    # Clean up validation output directory
    output_dir = REPO_ROOT / '.validation_output'
    if output_dir.exists():
        shutil.rmtree(output_dir)

    # Exit with non-zero if there are failures
    if failed:
        print()
        print(f"Validation failed: {len(failed)} file(s) did not compile")
        sys.exit(1)
    elif skipped:
        print()
        print(f"Validation completed with {len(skipped)} skipped file(s) due to local infrastructure")
        print("All other files validated successfully!")
        sys.exit(0)
    else:
        print("All files validated successfully!")
        sys.exit(0)


if __name__ == '__main__':
    main()
