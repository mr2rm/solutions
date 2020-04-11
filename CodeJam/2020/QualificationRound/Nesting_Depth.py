t = int(input())
for tc in range(1, t + 1):
    s = input()

    res, opened = '', 0
    for c in s:
        x = int(c)
        d = x - opened

        if d < 0:
            res += ')' * abs(d)
            d = 0

        res += '(' * d + c
        opened = x

    res += ')' * opened
    print("Case #{}: {}".format(tc, res))
