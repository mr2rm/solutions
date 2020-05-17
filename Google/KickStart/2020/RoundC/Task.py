t = int(input())
for tc in range(t):
    n, k = map(int, input().split())
    arr = map(int, input().split())

    d, res = k, 0
    for x in arr:
        if x == d:
            d -= 1
        else:
            d = k - int(x == k)
        if d == 0:
            d = k
            res += 1

    print("Case #%d: %d" % (tc + 1, res))
