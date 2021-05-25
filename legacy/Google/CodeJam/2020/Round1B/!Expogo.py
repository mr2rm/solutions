t = int(input())
for tc in range(1, t + 1):
    x, y = map(int, input().split())
    move = {
        'N': (0, 1),
        'W': (-1, 0),
        'S': (0, -1),
        'E': (1, 0),
    }

    res = 'IMPOSSIBLE'
    q = [((0, 0), '')]
    while q:
        (u, v), s = q.pop(0)
        if u == x and v == y:
            res = s
            break

        cnt = 2 ** len(s)
        for c, (du, dv) in move.items():
            tu, tv = u + cnt * du, v + cnt * dv
            if ((x - u) * (x - tu) <= 0) or ((y - v) * (y - tv) <= 0):
                continue
            q.append(((tu, tv), s + c))

    print("Case #%d: %s" % (tc, res))
