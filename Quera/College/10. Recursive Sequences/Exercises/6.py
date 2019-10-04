def get_vertex(a, b):
    return (
        (a[0] + b[0] + (3 ** 0.5) * (a[1] - b[1])) / 2,
        (a[1] + b[1] + (3 ** 0.5) * (b[0] - a[0])) / 2,
    )


def get_new_vertices(a, b):
    dx = (-1 if a[0] > b[0] else 1) * abs(a[0] - b[0]) / 3
    dy = (-1 if a[1] > b[1] else 1) * abs(a[1] - b[1]) / 3

    return (a[0] + dx, a[1] + dy), (b[0] - dx, b[1] - dy)


def f(a, b, level):
    if a[1] < b[1]:
        a, b = b, a
    c = get_vertex(a, b)

    if level == n:
        print(*c)
        return

    for u, v in [(a, b), (b, c), (c, a)]:
        uu, vv = get_new_vertices(u, v)
        f(uu, vv, level + 1)


n = int(input())
f((0, 0), (1000, 0), 0)
