n, k = map(int, input().split())

cnt = cur = 0
while cur + 1 != 1 or cnt == 0:
    cnt += 1
    cur = (cur + k) % n

print(cnt)
