n, k = map(int, input().split())
arr = map(int, input().split())

cur = res = 0
for x in arr:
    if cur + x <= k:
        cur += x
    else:
        res += 1
        cur = x

if cur:
    res += 1
print(res)
