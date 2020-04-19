t = int(input())

for tc in range(1, t + 1):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))

    res = arr[0]
    l, h = 1, d // arr[0]

    while l <= h:
        m = (l + h) // 2
        cd = m * arr[0]

        for x in arr:
            q, r = divmod(cd, x)
            if r != 0:
                q += 1

            cd = q * x
            if cd > d:
                l, h = l, m - 1
                break
        else:
            res = m
            l, h = m + 1, h

    res *= arr[0]
    print('Case #%d: %d' % (tc, res))
