import math


def count_divisors(n):
    cnt = 0
    for a in range(1, int(math.sqrt(n)) + 1):
        b, r = divmod(n, a)
        if r == 0:
            cnt += (2 if a != b else 1)
    return cnt


k = int(input())

i, n = 1, 0
while True:
    n += i
    if count_divisors(n) >= k:
        break
    i += 1

print(n)
