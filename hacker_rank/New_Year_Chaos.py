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
    # O(nlogn)
    res, arr = 0, []
    for x in q[::-1]:
        idx = bisect_left(arr, x)
        if idx > 2:
            res = 'Too chaotic'
            break
        arr.insert(idx, x)
        res += idx
    print(res)


if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        n = int(input().strip())
        q = list(map(int, input().rstrip().split()))
        minimumBribes(q)
