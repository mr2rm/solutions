n, m = map(int, input().split())
table, s = [input() for _ in range(n)], input()

res = 0
for i in range(n):
    for j in range(m - len(s) + 1):
        if s == table[i][j:j+len(s)]:
            res += 1
for i in range(n - len(s) + 1):
    for j in range(m):
        char_list = [table[i+k][j] for k in range(len(s))]
        if s == ''.join(char_list):
            res += 1
print(res)

