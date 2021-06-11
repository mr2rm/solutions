from math import sqrt, ceil

q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    res = int(sqrt(r)) - ceil(sqrt(l)) + 1
    print(res)
