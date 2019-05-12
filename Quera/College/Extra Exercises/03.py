k, a, b = map(int, input().split())

if a > b:   a, b = b, a
res = b - a

def get_range(x):
    m = x % k
    return [x - m, x + (k - m)]

for x in get_range(a):
    for y in get_range(b):
        d = abs(y - x) // k
        d += abs(a - x)
        d += abs(b - y)
        res = min(res, d)

print(res)
