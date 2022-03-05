#!/bin/python3

import enum
import math
import os
import random
import re
import sys

#
# Complete the 'bomberMan' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING_ARRAY grid
#

DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def bomberMan(n, grid):
    r, c = len(grid), len(grid[0])
    for i, row in enumerate(grid):
        grid[i] = [0 if x == 'O' else -1 for x in row]

    for t in range(2, n + 1):
        if t % 2 == 0:
            for i, row in enumerate(grid):
                grid[i] = [t if x == -1 else x for x in row]
        else:
            for i in range(r):
                for j in range(c):
                    if grid[i][j] != -1 and t - grid[i][j] == 3:
                        grid[i][j] = -1
                        for di, dj in DIRS:
                            x, y = i + di, j + dj
                            if 0 <= x < r and 0 <= y < c and grid[x][y] != -1 and t - grid[x][y] != 3:
                                grid[x][y] = -1

    res = []
    for i, row in enumerate(grid):
        res.append(''.join('O' if x != -1 else '.' for x in row))
    return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    r = int(first_multiple_input[0])
    c = int(first_multiple_input[1])
    n = int(first_multiple_input[2])

    grid = []
    for _ in range(r):
        grid_item = input()
        grid.append(grid_item)

    result = bomberMan(n, grid)
    print('\n'.join(result))
