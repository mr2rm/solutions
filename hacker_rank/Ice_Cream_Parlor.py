#!/bin/python3

from bisect import bisect_left
import math
import os
import random
import re
import sys

#
# Complete the 'icecreamParlor' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER m
#  2. INTEGER_ARRAY arr
#


def icecreamParlor(m, arr):
    n = len(arr)

    # O(n^2)
    # for i in range(n):
    #     for j in range(i + 1, n):
    #         if arr[i] + arr[j] == m:
    #             return (i + 1, j + 1)

    # O(nlogn)
    sorted_arr = sorted(arr)
    # Find flavors - first approach
    # for i, a in enumerate(sorted_arr):
    #     b = m - a
    #     j = bisect_left(sorted_arr, b)
    #     if j < n and sorted_arr[j] == b:
    #         break
    # Find flavors - second approach
    j = n - 1
    for i, a in enumerate(sorted_arr):
        while a + sorted_arr[j] > m:
            j -= 1
        b = sorted_arr[j]
        if a + b == m:
            break
    # Get indices for found flavors
    res, values = [], [a, b]
    for i, x in enumerate(arr):
        if x in values:
            values.remove(x)
            res.append(i + 1)
    return sorted(res)


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        m = int(input().strip())

        n = int(input().strip())
        arr = list(map(int, input().rstrip().split()))

        result = icecreamParlor(m, arr)
        print(' '.join(map(str, result)))
