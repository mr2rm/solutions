n = int(input())

res = 0
for a in range(1, n // 3 + 1):
    l, r = max(n // 2 - 2 * a + 1, 0), (n - 3 * a) // 2
    res += r - l + 1

print(res)
