#!/bin/python3

import math
import os
import random
import re
import sys


def getMaxCharCount(s, queries):
    n = len(s)
    s = s.lower()

    dp = [[0] * 26]
    for i, c in enumerate(s, start=1):
        dp.append(dp[-1].copy())
        dp[i][ord(c) - ord('a')] += 1

    res = []
    for x, y in queries:
        for i in reversed(range(26)):
            cnt = dp[y + 1][i] - dp[x][i]
            if cnt != 0:
                res.append(cnt)
                break

    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    q = int(input().strip())

    query = []

    for _ in range(q):
        query.append(list(map(int, input().rstrip().split())))

    ans = getMaxCharCount(s, query)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
