t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    cnt, m = {}, n // 2
    for a, b in zip(arr[:m], reversed(arr[m:])):
        x = a + b
        cnt.setdefault(x, 0)
        cnt[x] += 1
    print(cnt)

    res = m - max(cnt.values())
    print(res)
