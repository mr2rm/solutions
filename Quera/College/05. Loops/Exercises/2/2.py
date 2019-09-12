x, y = map(int, input().split())
res = -1
if y == x or y == x - 2:
    a, b = divmod(x, 2)
    res = 4 * a + b
    if y != x:
        res -= 2
print(res)
