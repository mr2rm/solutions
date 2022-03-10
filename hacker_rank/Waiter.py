#!/bin/python3

from audioop import cross
import math
import os
import random
import re
import sys

#
# Complete the 'waiter' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY number
#  2. INTEGER q
#

MAXN = 10_010


def get_primes():
    # ~O(nlogn)
    is_prime = [True] * MAXN
    is_prime[0] = is_prime[1] = False

    def cross_multiplications(a):
        for i in range(2, ((MAXN - 1) // a) + 1):
            is_prime[i * a] = False

    cross_multiplications(2)
    for x in range(3, int(math.sqrt(MAXN)) + 1, 2):
        if is_prime[x]:
            cross_multiplications(x)

    primes = [x for x in range(MAXN) if is_prime[x]]
    return primes


def waiter(number, q):
    res = []
    primes = get_primes()

    for p in primes[:q]:
        rem, div = [], []
        while number:
            x = number.pop()
            if x % p == 0:
                div.append(x)
            else:
                rem.append(x)
        while div:
            res.append(div.pop())
        number = rem
    while number:
        res.append(number.pop())

    return res


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    q = int(first_multiple_input[1])

    number = list(map(int, input().rstrip().split()))

    result = waiter(number, q)
    print('\n'.join(map(str, result)))
