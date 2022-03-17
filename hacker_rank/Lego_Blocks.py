#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'legoBlocks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#

MOD = int(1e9 + 7)


def pow(a, p):
    # O(logp) - Recursive
    # if p == 0:
    #     return 1
    # if p % 2 == 1:
    #     return a * pow(a, p - 1) % MOD
    # x = pow(a, p // 2)
    # return x * x % MOD

    # O(logp) - Iterative
    res = 1
    while p:
        if p % 2 == 1:
            res = res * a % MOD
        a = a * a % MOD
        p //= 2
    return res


def legoBlocks(n, m):
    # O(mlogn + m^2) - DP

    # O(n)
    row_dp = [0] * (m + 1)
    row_dp[0] = 1
    for i in range(1, m + 1):
        for j in range(1, 4 + 1):
            if i - j >= 0:
                row_dp[i] = (row_dp[i] + row_dp[i - j]) % MOD

    # O(mlogn)
    all_dp = [pow(row_dp[i], n) for i in range(m + 1)]

    # O(m^2)
    solid_dp = [0] * (m + 1)
    for i in range(m + 1):
        nvals = 0
        for j in range(1, i):
            nvals = (nvals + solid_dp[j] * all_dp[i - j]) % MOD
        solid_dp[i] = (all_dp[i] - nvals + MOD) % MOD

    return solid_dp[m]


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()
        n = int(first_multiple_input[0])
        m = int(first_multiple_input[1])

        result = legoBlocks(n, m)
        print(result)
