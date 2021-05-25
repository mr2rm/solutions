t = int(input())

for _ in range(t):
    n = int(input())
    arr = map(int, input().split())

    cnt, m = [0] * (n + 1), 0
    for x in arr:
        if cnt[x] == 0:
            m += 1
        cnt[x] += 1

    res = 0
    for i, c in enumerate(cnt):
        x = max(min(c - 1, m), min(c, m - 1))
        res = max(res, x)

    print(res)
