# Set 1 passed

from functools import reduce


def digit_sum(n):
    return sum(map(int, str(n)))


def digit_product(n):
    return reduce(lambda x, y: x * y, map(int, str(n)), 1)


T = int(input())
for t in range(T):
    A, B = map(int, input().split())
    res = 0
    for x in range(A, B + 1):
        if digit_product(x) % digit_sum(x) == 0:
            res += 1
    print(f'Case #{t + 1}: {res}')
