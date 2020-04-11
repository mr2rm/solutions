def has_repeated_value(arr, n):
    mark = [False] * (n + 1)
    for x in arr:
        if mark[x]:
            return True
        mark[x] = True
    return False


t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    mat = [list(map(int, input().split())) for _ in range(n)]

    k = sum(mat[i][i] for i in range(n))

    r = 0
    for i in range(n):
        r += int(has_repeated_value(mat[i], n))

    c = 0
    for j in range(n):
        col = [mat[i][j] for i in range(n)]
        c += int(has_repeated_value(col, n))

    print("Case #{}: {} {} {}".format(tc, k, r, c))
