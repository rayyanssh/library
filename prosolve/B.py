import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop
from itertools import accumulate, permutations, combinations
from math import gcd, lcm, inf

#!/usr/bin/env python3
# Competitive Programming Template (Python)


input = sys.stdin.readline


def ints():
    return list(map(int, input().split()))


def solve():
    # Example:
    # n = int(input())
    # a = ints()
    # print(sum(a))
    pass


def main():
    t = 1
    # Uncomment if multiple test cases:
    # t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()