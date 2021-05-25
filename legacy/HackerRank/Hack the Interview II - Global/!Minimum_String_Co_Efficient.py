#!/bin/python3

import math
import os
import random
import re
import sys


def calc(s, c):
    s = s.rstrip(s[-1])

    dp = [0]
    n, i = len(s), 0
    while i < n:
        j = i
        while j < n and s[j] != c:
            j += 1

        k = j
        while k < n and s[k] == c:
            k += 1

        x, y = j - i, k - j
        if i > 0:
            cur = dp[-1] + x + y
            dp.append(cur)
        elif x != 0:
            dp.append(y)
        i = k

    return dp


def gttr(ls, idx, default):
    return ls[idx] if idx < len(ls) else default


def minStringCoeff(s, p):
    score = len(s.lstrip(s[0]).rstrip(s[-1]))

    dpl = [calc(s, c) for c in '01']
    dpr = [calc(s[::-1], c) for c in '01']

    res = score
    for l in range(p + 1):
        r = p - l
        x = max(gttr(dpl[0], l, score), gttr(dpl[1], l, score))
        y = max(gttr(dpr[0], r, score), gttr(dpr[1], r, score))
        res = min(res, max(score - x - y, 0))

    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    p = int(first_multiple_input[1])

    s = input()

    res = minStringCoeff(s, p)

    fptr.write(str(res) + '\n')

    fptr.close()
