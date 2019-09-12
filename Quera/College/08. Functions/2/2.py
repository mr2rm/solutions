def gcd(a, b):
    if a > b:
        a, b = b, a
    while a:
        a, b = b % a, a
    return b

def lcm(a, b):
    return a * b // gcd(a, b)

n = int(input())
res = 1
for i in range(1, n):
    if gcd(i, n) == 1:
        res = lcm(res, i)
print(res)

