#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maxSubarray' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#


def max_subseq(arr):
    # O(n)
    res = None
    for x in arr:
        if x >= 0:
            res = (0 if res is None else res) + x
    if res is None:
        res = max(arr)
    return res


def max_subarr(arr):
    # O(n)
    res, curr = None, 0
    for x in arr:
        curr += x
        if curr < 0:
            curr = 0
        elif res is None or curr > res:
            res = curr
    if res is None:
        res = max(arr)
    return res


def maxSubarray(arr):
    # O(n)
    return max_subarr(arr), max_subseq(arr)


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())
        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)
        print(' '.join(map(str, result)))
