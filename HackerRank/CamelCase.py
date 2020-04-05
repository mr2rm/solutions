#!/bin/python3

import math
import os
import random
import re
import sys


def camelcase(s):
    # return sum(c.isupper() for c in s) + 1
    # return len(list(filter(lambda c: c.isupper(), s))) + 1
    return len(re.findall(r'[A-Z]', s)) + 1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = camelcase(s)

    fptr.write(str(result) + '\n')

    fptr.close()
