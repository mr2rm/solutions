t = int(input())
for _ in range(t):
    x, n, m = map(int, input().split())

    for _ in range(n):
        y = x // 2 + 10
        if y > x:
            break
        x = y
        if x <= 0:
            break

    x -= 10 * m
    print('YES' if x <= 0 else 'No')
