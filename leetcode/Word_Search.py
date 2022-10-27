from typing import List


class Solution:
    MAX_N = 10
    DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def find(self, x: int, y: int, word: str):
        if not word:
            return True

        # This leads to TLE!
        # if not (0 <= x < len(self.board) and 0 <= y < len(self.board[0])):
        #     return False

        if x < 0 or x >= len(self.board) or y < 0 or y >= len(self.board[0]):
            return False
        if self.visited[x][y] or self.board[x][y] != word[0]:
            return False

        # Leads to TLE!
        # self.visited[x][y] = True
        # for i, j in self.DIRS:
        #     tx, ty = x + i, y + j
        #     if self.find(tx, ty, word[1:]):
        #         return True
        # self.visited[x][y] = False
        # return False

        self.visited[x][y] = True
        res = self.find(x - 1, y, word[1:]) or self.find(x, y + 1, word[1:]) or self.find(
            x + 1, y, word[1:]) or self.find(x, y - 1, word[1:])
        self.visited[x][y] = False
        return res

    def exist(self, board: List[List[str]], word: str) -> bool:
        # DFS & Backtrack - Time: O(n^4), Space: O(n^2)
        self.board = board
        self.visited = [[False] * self.MAX_N for _ in range(self.MAX_N)]
        for i, row in enumerate(board):
            for j in range(len(row)):
                if self.find(i, j, word):
                    return True
        return False
