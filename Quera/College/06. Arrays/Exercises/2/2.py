n, res = int(input()), -1

for _ in range(n):
    word = input().strip()
    unique_count = len(set(word))
    res = max(unique_count, res)

print(res)
