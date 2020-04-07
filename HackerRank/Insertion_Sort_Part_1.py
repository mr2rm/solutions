#!/bin/python3

import math
import os
import random
import re
import sys


def insertionSort1(n, arr):
    x = arr[-1]
    for i in reversed(range(n)):
        found = (i == 0 or arr[i - 1] <= x)
        arr[i] = x if found else arr[i - 1]
        print(' '.join(map(str, arr)))
        if found:
            break


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    insertionSort1(n, arr)
