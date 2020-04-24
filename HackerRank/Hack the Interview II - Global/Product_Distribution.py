#!/bin/python3

import math
import os
import random
import re
import sys


MOD = 1e9 + 7


def maxScore(a, m):
    a.sort()
    q, r = divmod(len(a), m)

    res = 0
    for i in range(q):
        j = i * m
        res += (i + 1) * sum(a[j:j + m])
        res %= MOD

    if r:
        res += q * sum(a[-r:])
        res %= MOD

    return int(res)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    a = list(map(int, input().rstrip().split()))

    ans = maxScore(a, m)

    fptr.write(str(ans) + '\n')

    fptr.close()
