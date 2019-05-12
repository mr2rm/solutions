n, x = input().split()
n = int(n)

glass_index = {'L': 0, 'M': 1, 'R': 2}
glasses = [False] * 3
glasses[glass_index[x]] = True

for _ in range(n):
    x, y = input().split()
    i, j = glass_index[x], glass_index[y]
    glasses[i], glasses[j] = glasses[j], glasses[i]

for glass, index in glass_index.items():
    if glasses[index]:
        print(glass)

