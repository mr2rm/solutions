#!/bin/python3

from collections import defaultdict
import math
import os
import random
import re
import sys

#
# Complete the 'anagram' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#


def count_chars(s):
    cnt = defaultdict(int)
    for c in s:
        cnt[c] += 1
    return cnt


def anagram(s):
    # O(n)
    n = len(s)
    if n % 2 == 1:
        return -1
    mid = n // 2
    lcnt, rcnt = count_chars(s[:mid]), count_chars(s[mid:])
    res = 0
    for c, cnt in lcnt.items():
        if cnt > rcnt[c]:
            res += cnt - rcnt[c]
    return res


if __name__ == '__main__':
    q = int(input().strip())
    for q_itr in range(q):
        s = input()
        result = anagram(s)
        print(result)
