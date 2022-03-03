#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'counterGame' function below.
#
# The function is expected to return a STRING.
# The function accepts LONG_INTEGER n as parameter.
#


def counterGame(n):
    # O(log2(n))
    res = 0
    while n > 1:
        if n & (n - 1) == 0:
            n >>= 1
        else:
            n -= 1 << int(math.log2(n))
        res = 1 - res
    if res == 0:
        return 'Richard'
    return 'Louise'


if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        n = int(input().strip())
        result = counterGame(n)
        print(result)
