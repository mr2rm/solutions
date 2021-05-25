n, m = map(int, input().split())

mat = []
for i in range(n):
    row = list(map(int, input().split()))
    mat.append(row)


def check(x, y):
    return 0 <= x < n and 0 <= y < m and dp[x][y] != 0


dp = [[0] * m for _ in range(n)]
for i in range(0, n, 2):
    for j in range(0, m):
        if mat[i][j] == 0:
            continue

        if check(i, j - 1):
            dp[i][j] = dp[i][j - 1] + mat[i][j]

        cnt = (n - i) // 2
        k = j - 1 if cnt % 2 == 0 else j + 1
        if check(i - 2, k):
            dp[i][j] = max(dp[i][j], dp[i - 2][k] + mat[i][j])

        if i == 0:
            dp[i][j] = dp[i][j] or mat[i][j]

res = max(dp[n - 1])
print(res)
