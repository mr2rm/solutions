#!/bin/python3

from collections import deque
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
    # O(n) - Adhoc
    res = tank = 0
    for i, (pet, dist) in enumerate(petrolpumps):
        tank += pet - dist
        if tank < 0:
            res, tank = i + 1, 0
    return res

    # O(n) - Queue
    # queue = deque()
    # queue.append(0)
    # n, tank = len(petrolpumps), 0
    # while len(queue) < n:
    #     i = queue[-1]
    #     tank += petrolpumps[i][0] - petrolpumps[i][1]
    #     if tank < 0:
    #         tank = 0
    #         queue.clear()
    #     queue.append((i + 1) % n)
    # return queue[0]

    # O(n) - Circural Queue
    # n, tank = len(petrolpumps), None
    # i = j = 0
    # while tank is None or i != j:
    #     if tank is None:
    #         tank = 0
    #     tank += petrolpumps[i][0] - petrolpumps[i][1]
    #     i = (i + 1) % n
    #     if tank < 0:
    #         tank, j = None, i
    # return i

    # O(n) - Math
    # res = mn = tank = 0
    # for i, (pet, dist) in enumerate(petrolpumps):
    #     if tank < mn:
    #         res, mn = i, tank
    #     tank += pet - dist
    # return res


if __name__ == '__main__':
    n = int(input().strip())

    petrolpumps = []
    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)
    print(result)
