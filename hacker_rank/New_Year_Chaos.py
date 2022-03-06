#!/bin/python3

from bisect import bisect_left
import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#


def minimumBribes(q):
    res = 0

    # O(nlogn)
    # arr = []
    # for x in q[::-1]:
    #     idx = bisect_left(arr, x)
    #     if idx > 2:
    #         res = 'Too chaotic'
    #         break
    #     arr.insert(idx, x)
    #     res += idx

    # O(n)
    for i in reversed(range(len(q))):
        x = i + 1
        if q[i] == x:
            continue
        if q[i - 1] != x and q[i - 2] != x:
            res = 'Too chaotic'
            break
        if q[i - 1] == x:
            q[i - 1], q[i] = q[i], q[i - 1]
            res += 1
        else:
            q[i - 2], q[i - 1], q[i] = q[i - 1], q[i], q[i - 2]
            res += 2

    print(res)


if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        n = int(input().strip())
        q = list(map(int, input().rstrip().split()))
        minimumBribes(q)
