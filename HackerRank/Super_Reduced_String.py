#!/bin/python3

import math
import os
import random
import re
import sys


def superReducedString(s):
    while s:
        found = False
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                s, found = s[:i] + s[i + 2:], True
                break

        if not found:
            break

    return s or 'Empty String'


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = superReducedString(s)

    fptr.write(result + '\n')

    fptr.close()
