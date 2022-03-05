#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#


def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(a, b)


def getTotalX(a, b):
    # O(n) = O(100 * (n + m))
    res = 0
    for x in range(1, 101):
        if all(x % i == 0 for i in a) and all(i % x == 0 for i in b):
            res += 1
    return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    m = int(first_multiple_input[1])
    arr = list(map(int, input().rstrip().split()))
    brr = list(map(int, input().rstrip().split()))
    total = getTotalX(arr, brr)
    print(total)
