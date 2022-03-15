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


def max_sum_subseq(arr):
    # O(n) - Greedy

    maxi, res = arr[0], 0
    for x in arr:
        maxi = max(maxi, x)
        if x >= 0:
            res += x
    if maxi < 0:
        res = maxi
    return res

    # res = None
    # for x in arr:
    #     if x >= 0:
    #         res = (0 if res is None else res) + x
    # if res is None:
    #     res = max(arr)
    # return res


def max_sum_subarr(arr):
    # O(n) - Kadane (v2)
    res = last = arr[0]
    for x in arr[1:]:
        if last < 0:
            last = 0
        last += x
        res = max(res, last)
    return res

    # O(n) - DP
    # res = last = arr[0]
    # for x in arr[1:]:
    #     last = max(last + x, x)
    #     res = max(res, last)
    # return res

    # O(n) - Kadane (v1)
    # res, curr = None, 0
    # for x in arr:
    #     curr += x
    #     if curr < 0:
    #         curr = 0
    #     elif res is None or curr > res:
    #         res = curr
    # if res is None:
    #     res = max(arr)
    # return res


def maxSubarray(arr):
    # O(n)
    return max_sum_subarr(arr), max_sum_subseq(arr)


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())
        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)
        print(' '.join(map(str, result)))
