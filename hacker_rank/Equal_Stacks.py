#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalStacks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h1
#  2. INTEGER_ARRAY h2
#  3. INTEGER_ARRAY h3
#


def remove_cylinders(stack, height, target):
    while height > target:
        height -= stack.pop()
    return height


def equalStacks(h1, h2, h3):
    # O(n)
    h1.reverse(), h2.reverse(), h3.reverse()
    s1, s2, s3 = sum(h1), sum(h2), sum(h3)
    while s1 != s2 or s2 != s3:
        t = min((s1, s2, s3))
        s1 = remove_cylinders(h1, s1, t)
        s2 = remove_cylinders(h2, s2, t)
        s3 = remove_cylinders(h3, s3, t)
    return s1


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])
    n2 = int(first_multiple_input[1])
    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))
    h2 = list(map(int, input().rstrip().split()))
    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)
    print(result)
