#!/bin/python3

from collections import defaultdict
from email.policy import default
import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#


def isValid(s):
    # O(n)
    cnts = defaultdict(int)
    for c in s:
        cnts[c] += 1
    freqs = set(cnts.values())
    n, m = len(cnts), len(freqs)
    if m > 2:
        return 'NO'
    if m == 1:
        return 'YES'
    if n * min(freqs) + 1 == len(s) or (n - 1) * max(freqs) + 1 == len(s):
        return 'YES'
    return 'NO'


if __name__ == '__main__':
    s = input()
    result = isValid(s)
    print(result)
