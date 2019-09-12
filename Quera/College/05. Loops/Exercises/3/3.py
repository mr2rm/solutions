a, b, x = map(int, input().split())
res = 0
for n in range(1, min(a+1, x)):
    if a % n == 0:
        for m in range(1, min(b+1, x-n+1)):
            if b % m == 0:
                res += 1
print(res)
