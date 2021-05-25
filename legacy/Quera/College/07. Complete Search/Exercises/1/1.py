n, x, y = map(int, input().split())

found = False
for a in range(n // x + 1):
    b, r = divmod(n - a * x, y)
    if r == 0:
        print(a, b)
        found = True
        break

if not found:
    print(-1)
