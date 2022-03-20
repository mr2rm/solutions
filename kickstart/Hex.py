DIR = [
    (-1, 0),
    (-1, 1),
    (0, 1),
    (1, 0),
    (1, -1),
    (0, -1),
]

n, comp_num = None, None
mat, mark = [], []


def dfs(x, y, stone):
    mark[x][y] = comp_num
    for dx, dy in DIR:
        tx, ty = x + dx, y + dy
        if 0 <= tx < n and 0 <= ty < n and mat[tx][ty] == stone and not mark[tx][ty]:
            dfs(tx, ty, stone)


def count_blue_paths():
    global comp_num
    start = set()
    for i in range(n):
        if mat[i][0] == 'B' and not mark[i][0]:
            comp_num += 1
            start.add(comp_num)
            dfs(i, 0, 'B')

    for i in range(n):
        

    end = set()
    for i in range(n):
        if mat[i][n - 1] == 'B':
            end.add(mark[i][n - 1])

    return len(start & end)


def count_red_paths():
    global comp_num
    start = set()
    for j in range(n):
        if mat[0][j] == 'R' and not mark[0][j]:
            comp_num += 1
            start.add(comp_num)
            dfs(0, j, 'R')

    end = set()
    for j in range(n):
        if mat[n - 1][j] == 'R':
            end.add(mark[n - 1][j])

    return len(start & end)


def game_status(board_size, board):
    global n, mat, mark, comp_num
    n, mat = board_size, board

    # Check number of stones
    blue_cnt = red_cnt = 0
    for row in board:
        for stone in row:
            if stone == "R":
                red_cnt += 1
            if stone == "B":
                blue_cnt += 1
    if abs(blue_cnt - red_cnt) > 1:
        return "Impossible"

    # Check number of connected paths
    mark, comp_num = [[0] * board_size for _ in range(board_size)], 0
    blue_path_count = count_blue_paths()
    red_path_count = count_red_paths()
    if max(blue_path_count, red_path_count) > 1:
        return "Impossible"

    # Check winner
    if blue_path_count:
        return "Blue wins" if blue_cnt >= red_cnt else "Impossible"
    if red_path_count:
        return "Red wins" if red_cnt >= blue_cnt else "Impossible"
    return "Nobody wins"


def main():
    test_cases = int(input())
    for test_case in range(1, test_cases + 1, 1):
        board_size = int(input())
        board = []
        for _ in range(board_size):
            board.append(list(input().strip()))

        ans = game_status(board_size, board)

        print("Case #{}: {}".format(test_case, ans))


if __name__ == "__main__":
    main()
