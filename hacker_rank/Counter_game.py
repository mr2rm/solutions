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


def msb(n):
    for i in reversed(range(64)):
        if n & (1 << i) != 0:
            return 1 << i
    return 0


def can_win(n):
    if n == 1:
        return False
    if n & (n - 1) == 0:
        return not can_win(n >> 1)
    return not can_win(n - msb(n))


def counterGame(n):
    # O(log2(n))
    # res = 0
    # while n > 1:
    #     if n & (n - 1) == 0:
    #         n >>= 1
    #     else:
    #         n -= 1 << int(math.log2(n))
    #     res = 1 - res

    # O(log2(n))
    # res = can_win(n)

    # O(log2(n))
    # bits = bin(n)[2:]
    # tz_cnt = bits[::-1].find('1')
    # lo_cnt = bits.count('1')
    # res = (tz_cnt + lo_cnt - 1) % 2

    # O(log2(n))
    res = bin(n - 1).count('1') % 2

    if res:
        return 'Louise'
    return 'Richard'


if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        n = int(input().strip())
        result = counterGame(n)
        print(result)
