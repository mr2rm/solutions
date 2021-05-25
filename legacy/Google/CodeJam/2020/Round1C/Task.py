t = int(input())
for tc in range(t):
    x, y, s = input().split()
    x, y = int(x), int(y)

    mov = {
        'S': (0, -1),
        'N': (0, 1),
        'E': (1, 0),
        'W': (-1, 0)
    }

    res = 'IMPOSSIBLE'
    for i, c in enumerate(s, start=1):
        x += mov[c][0]
        y += mov[c][1]
        if abs(x) + abs(y) <= i:
            res = i
            break

    print('Case #{}: {}'.format(tc + 1, res))
