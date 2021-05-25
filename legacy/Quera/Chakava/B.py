n, m = map(int, input().split())
walls, marks = [], []
for i in range(n):
    walls.append(input())
    marks.append([False] * m)


def is_good_wall(x, y):
    z = y
    while z < m and walls[x][z] == '+':
        marks[x][z] = True
        z += 1

    for i in range(x + 1, n):
        window_cnt = 0
        for j in range(y, z):
            if walls[i][j] == '+':
                marks[i][j] = True
                window_cnt += 1

        if window_cnt == 0:
            break

        if window_cnt == z - y:
            window_cnt += int(walls[i][y-1] == '+') + int(walls[i][z] == '+')
        if window_cnt != z - y:
            return False

    return True


result = True
for i in range(n):
    for j in range(m):
        if walls[i][j] == '+' and not marks[i][j]:
            result &= is_good_wall(i, j)

result = 'good wall' if result else 'bad wall'
print(result)
