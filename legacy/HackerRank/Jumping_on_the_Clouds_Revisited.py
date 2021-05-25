#!/bin/python3

import math
import os
import random
import re
import sys


def jumpingOnClouds(c, k):
    i = cost = 0
    while True:
        i = (i + k) % n
        cost += 3 if c[i] == 1 else 1
        if i == 0:
            break

    return 100 - cost


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c, k)

    fptr.write(str(result) + '\n')

    fptr.close()
