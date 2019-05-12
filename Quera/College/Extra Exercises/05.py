n = int(input())
arr = list(map(int, input().split()))

cnt, res = 0, 0
for x in arr:
    if x >= 0:
        if cnt < x:
            res += x - cnt
            cnt = 0
        else:
            cnt -= x
    else:
        cnt += abs(x)

print(res)
