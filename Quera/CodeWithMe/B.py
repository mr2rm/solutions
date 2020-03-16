n, k = map(int, input().split())
prices = list(map(int, input().split()))

if k == 1:
    res = max(prices)
elif k > 2:
    res = min(prices)
else:
    res = 5_000_000
    for i in range(1, n):
        tmpres = min(max(prices[:i]), max(prices[i:]))
        res = min(res, tmpres)

print(res)
