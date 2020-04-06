#!/bin/python3

import math
import os
import random
import re
import sys


def permutationEquation(p):
    res = []
    for x in range(1, len(p) + 1):
        x_idx = p.index(x)
        y = p.index(x_idx + 1) + 1
        res.append(y)

    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = list(map(int, input().rstrip().split()))

    result = permutationEquation(p)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
