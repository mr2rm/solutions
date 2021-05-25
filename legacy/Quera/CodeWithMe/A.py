x, n = int(input()), int(input())

res = x
if n == 0:
    res = 20
elif n != 7:
    res = max(x - n, 0)

print(res)
