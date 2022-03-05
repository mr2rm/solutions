#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sumXor' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER n as parameter.
#


def sumXor(n):
    # log(n)
    if n == 0:
        return 1
    return 2 ** bin(n).count('0', 2)


if __name__ == '__main__':
    n = int(input().strip())
    result = sumXor(n)
    print(result)
