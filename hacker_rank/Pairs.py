#!/bin/python3

from bisect import bisect_left
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
    # O(n) - Hash Table (`unordered_set` in C++)
    items = set(arr)
    # res = 0
    # for x in arr:
    #     if x + k in items:
    #         res += 1
    plus_k_items = set(x + k for x in arr)
    res = len(items & plus_k_items)
    return res

    # O(nlogn) - Two Pointers
    # n = len(arr)
    # arr.sort()
    # res = j = 0
    # for x in arr:
    #     while j < n and arr[j] < x + k:
    #         j += 1
    #     if j == n:
    #         break
    #     if arr[j] == x + k:
    #         res += 1
    # return res

    # O(nlogn) - Binary Search (`set` in C++)
    # arr.sort()
    # n, res = len(arr), 0
    # for x in arr:
    #     j = bisect_left(arr, x + k)
    #     if j == n:
    #         break
    #     if arr[j] == x + k:
    #         res += 1
    # return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))
    result = pairs(k, arr)
    print(result)
