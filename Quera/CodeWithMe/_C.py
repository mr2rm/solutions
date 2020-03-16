n, m = map(int, input().split())

mat = []
for i in range(n):
    row = list(map(int, input().split()))
    mat.append(row)


def check(x, y):
    return 0 <= x < n and 0 <= y < m and mat[x][y] != 0


def solve(x, y, l):
    score = 0

    if check(x, y - 1):
        tmp = solve(x, y - 1, l)
        if tmp != -1:
            score = tmp

    ty = y - 1 if l % 2 == 0 else y + 1
    if check(x - 2, ty):
        tmp = solve(x - 2, ty, l + 1)
        if tmp != -1:
            score = max(score, tmp)

    if score == 0 and x != 0:
        return -1

    return mat[x][y] + score


res = 0
for i in range(m):
    if mat[n - 1][i] != 0:
        res = max(res, solve(n - 1, i, 0))

print(res)
