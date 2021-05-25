n = int(input())
colors = list(map(int, input().split()))

count = [0] * 111
for color in colors:
    count[color] += 1

res = -1
for color in range(1, 101):
    if not count[color]:
        continue
    if res == -1 or count[color] < count[res]:
        res = color

print(res)
