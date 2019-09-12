n, m = tuple(map(int, input().split()))
cost, res = [], 0

for _ in range(n):
    cost.append(list(map(int, input().split())))

for _ in range(m):
    x, y = tuple(map(int, input().split()))
    res += cost[x-1][y-1]

print(res)
