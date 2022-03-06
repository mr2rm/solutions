#!/bin/python3

from bisect import bisect_left
import enum
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
    res = []

    # unique_ranked = []
    # for i, score in enumerate(ranked):
    #     if i == 0 or score != ranked[i - 1]:
    #         unique_ranked.append(score)
    # n = len(unique_ranked)

    # O(nlogn)
    # unique_ranked.reverse()
    # for score in player:
    #     idx = bisect_left(unique_ranked, score)
    #     if idx == n or unique_ranked[idx] != score:
    #         idx -= 1
    #     res.append(n - idx)

    # O(n)
    # pt = n - 1
    # for score in player:
    #     while pt >= 0 and score >= unique_ranked[pt]:
    #         pt -= 1
    #     res.append(pt + 2)

    # O(n)
    rank = [1]
    for pt, score in enumerate(ranked[1:], start=1):
        pos = rank[pt - 1]
        if score != ranked[pt - 1]:
            pos += 1
        rank.append(pos)
    pt = len(ranked) - 1
    for score in player:
        while pt >= 0 and score >= ranked[pt]:
            pt -= 1
        res.append(1 if pt == -1 else rank[pt] + 1)

    return res


if __name__ == '__main__':
    ranked_count = int(input().strip())
    ranked = list(map(int, input().rstrip().split()))
    player_count = int(input().strip())
    player = list(map(int, input().rstrip().split()))
    result = climbingLeaderboard(ranked, player)
    print('\n'.join(map(str, result)))
