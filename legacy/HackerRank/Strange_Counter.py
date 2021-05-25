#!/bin/python3

import math
import os
import random
import re
import sys


def strangeCounter(t):
    i, x = 0, 1
    while True:
        n = 3 * (2 ** i)
        if x <= t < x + n:
            return n - (t - x)
        x += n
        i += 1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    result = strangeCounter(t)

    fptr.write(str(result) + '\n')

    fptr.close()
