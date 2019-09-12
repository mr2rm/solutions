n, l = tuple(map(int, input().split()))
curr = prev = 0
for i in range(n):
    d, r, g = tuple(map(int, input().split()))
    curr += d - prev
    curr_timer = curr % (r + g)
    if curr_timer < r:
        curr += r - curr_timer
    prev = d
curr += l - prev
print(curr)
