#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

BRACKETS = {
    '}': '{',
    ']': '[',
    ')': '(',
}


def isBalanced(s):
    # O(n)
    stack = []
    for c in s:
        if c in BRACKETS.values():
            stack.append(c)
        else:
            if not stack or stack[-1] != BRACKETS[c]:
                return 'NO'
            stack.pop()
    if stack:
        return 'NO'
    return 'YES'


if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        s = input()
        result = isBalanced(s)
        print(result)
