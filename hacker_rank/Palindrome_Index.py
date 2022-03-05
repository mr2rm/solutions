#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'palindromeIndex' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#


def check_index(s, i):
    t = s[:i] + s[i + 1:]
    return t == t[::-1]


def palindromeIndex(s):
    # O(n)
    n = len(s)
    for i in range(n // 2):
        j = n - i - 1
        if s[i] != s[j]:
            if check_index(s, i):
                return i
            if check_index(s, j):
                return j
            return -1
    return -1


if __name__ == '__main__':
    q = int(input().strip())
    for q_itr in range(q):
        s = input()
        result = palindromeIndex(s)
        print(result)
