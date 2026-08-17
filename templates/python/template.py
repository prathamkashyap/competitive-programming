"""
Universal Competitive Programming Boilerplate in Python 3
Author: Pratham Kashyap
"""

import sys
import math
from collections import defaultdict, deque, Counter
import heapq

# Increase recursion depth for deep DFS/Recursion
sys.setrecursionlimit(200000)

def input():
    return sys.stdin.readline().rstrip()

def print_ans(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)

def solve():
    # Read input and solve single testcase
    pass

def main():
    try:
        line = input()
        if not line:
            return
        t = int(line)
        for _ in range(t):
            solve()
    except (EOFError, ValueError):
        pass

if __name__ == "__main__":
    main()
