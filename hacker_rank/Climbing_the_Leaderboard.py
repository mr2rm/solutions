#!/bin/python3

from bisect import bisect_left
import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#


def climbingLeaderboard(ranked, player):
    # O(nlogn)
    unique_ranked = []
    for i, score in enumerate(ranked):
        if i == 0 or score != ranked[i - 1]:
            unique_ranked.append(score)
    unique_ranked.reverse()
    n, res = len(unique_ranked), []
    for score in player:
        idx = bisect_left(unique_ranked, score)
        if idx == n or unique_ranked[idx] != score:
            idx -= 1
        res.append(n - idx)
    return res


if __name__ == '__main__':
    ranked_count = int(input().strip())
    ranked = list(map(int, input().rstrip().split()))
    player_count = int(input().strip())
    player = list(map(int, input().rstrip().split()))
    result = climbingLeaderboard(ranked, player)
    print('\n'.join(map(str, result)))
