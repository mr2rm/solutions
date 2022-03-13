#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'truckTour' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
#


def truckTour(petrolpumps):
    # O(n)
    res = tank = 0
    for i, (pet, dist) in enumerate(petrolpumps):
        tank += pet - dist
        if tank < 0:
            res, tank = i + 1, 0
    return res


if __name__ == '__main__':
    n = int(input().strip())

    petrolpumps = []
    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)
    print(result)
