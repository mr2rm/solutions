#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'balancedSums' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#


def balancedSums(arr):
    n = len(arr)

    # O(n)
    # partial_sum = []
    # for i, x in enumerate(arr):
    #     t = x + (0 if i == 0 else partial_sum[i - 1])
    #     partial_sum.append(t)
    # for i, x in enumerate(arr):
    #     if (partial_sum[i] - x) == (partial_sum[n - 1] - partial_sum[i]):
    #         return 'YES'
    # return 'NO'

    # O(n)
    # total = sum(arr)
    # partial_sum = 0
    # for x in arr:
    #     if partial_sum == (total - partial_sum - x):
    #         return 'YES'
    #     partial_sum += x
    # return 'NO'

    # O(n)
    lsum, rsum = 0, sum(arr)
    for i, x in enumerate(arr):
        if lsum == rsum - x:
            return 'YES'
        lsum += x
        rsum -= arr[i]
    return 'NO'


if __name__ == '__main__':
    T = int(input().strip())
    for T_itr in range(T):
        n = int(input().strip())
        arr = list(map(int, input().rstrip().split()))
        result = balancedSums(arr)
        print(result)
