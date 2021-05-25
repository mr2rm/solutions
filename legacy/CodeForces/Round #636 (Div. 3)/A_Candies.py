t = int(input())
for _ in range(t):
    n = int(input())
    for k in range(2, 30):
        x, r = divmod(n, 2 ** k - 1)
        if r == 0:
            print(x)
            break
