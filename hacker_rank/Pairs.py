#!/bin/python3

from bisect import bisect_left, bisect_right
from collections import defaultdict
import math
import os
import random
import re
import sys

#
# Complete the 'pairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#


def pairs(k, arr):
    # O(nlogn) - Two Pointers
    n = len(arr)
    arr.sort()
    res = j = 0
    for x in arr:
        for j in range(j, n):
            if arr[j] > x + k:
                break
            if arr[j] == x + k:
                res += 1
    return res

    # O(nlogn) - Binary Search
    # arr.sort()
    # n, res = len(arr), 0
    # for a in arr:
    #     b = a + k
    #     j = bisect_left(arr, b)
    #     if j == n:
    #         break
    #     if arr[j] == b:
    #         res += bisect_right(arr, b) - j
    # return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))
    result = pairs(k, arr)
    print(result)
