n, m = tuple(map(int, input().split()))
res = 0
for _ in range(n):
    res += input().count('*')
print(res)
