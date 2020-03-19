#!/bin/python3

import math
import os
import random
import re
import sys


def biggerIsGreater(w):
    max_char = s = w[-1]
    char_index = [-1] * 128
    char_index[ord(w[-1])] = 0

    res = None
    for i in range(len(w) - 2, -1, -1):
        c = w[i]
        if c < max_char:
            for j in range(ord(c) + 1, ord(max_char) + 1):
                idx = char_index[j]
                if idx != -1:
                    lt = list(s)
                    lt[idx] = c
                    res = w[:i] + s[idx] + ''.join(sorted(lt))
                    break
            break

        max_char = c
        char_index[ord(c)] = len(s)
        s += c

    res = res or 'no answer'
    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input())

    for T_itr in range(T):
        w = input()

        result = biggerIsGreater(w)

        fptr.write(result + '\n')

    fptr.close()
