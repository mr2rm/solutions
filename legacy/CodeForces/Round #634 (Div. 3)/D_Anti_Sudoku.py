t = int(input())

for _ in range(t):
    mat = []
    for _ in range(9):
        row = list(map(int, input()))
        mat.append(row)

    for i in range(9):
        x, y = divmod(i, 3)
        j = x + 3 * y
        a = 10 - mat[i][j]
        mat[i][j] = 1 if a == 5 else a
        row = ''.join(map(str, mat[i]))
        print(row)
