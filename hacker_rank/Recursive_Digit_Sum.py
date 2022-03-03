#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superDigit' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING n
#  2. INTEGER k
#


def sumOfDigits(s: str):
    return sum(map(int, s))


def superDigit(n, k):
    # O(log10(n))
    res = k * sumOfDigits(n)
    while res > 9:
        res = sumOfDigits(str(res))
    return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = first_multiple_input[0]
    k = int(first_multiple_input[1])
    result = superDigit(n, k)
    print(result)
