#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'configureProjectPresentation' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY friendships
#


def configureProjectPresentation(n, friendships):
    adj = [set() for _ in range(n + 1)]
    for u, v in friendships:
        adj[u].add(v)
        adj[v].add(u)

    dist = [-1] * (n + 1)
    q, dist[2] = [2], 0
    while q:
        u = q.pop(0)
        if dist[u] == 2 or u == 1:
            continue
        for v in adj[u]:
            if dist[v] == -1:
                q.append(v)
                dist[v] = dist[u] + 1

    res = [u for u in sorted(adj[1]) if dist[u] == -1]
    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        freiendships = []

        for _ in range(m):
            freiendships.append(list(map(int, input().rstrip().split())))

        result = configureProjectPresentation(n, freiendships)

        fptr.write(' '.join(map(str, result)) or '-1')
        fptr.write('\n')

    fptr.close()
