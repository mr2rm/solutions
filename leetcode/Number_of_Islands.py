from typing import List


class Solution:
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def __init__(self):
        self.grid = None
        self.n = None
        self.m = None

    def dfs(self, x, y):
        self.grid[x][y] = None
        for dx, dy in self.dirs:
            tx, ty = x + dx, y + dy
            if 0 <= tx < self.n and 0 <= ty < self.m and self.grid[tx][ty] == '1':
                self.dfs(tx, ty)

    def numIslands(self, grid: List[List[str]]) -> int:
        # Time: O(n^2 + 2*n^2) = O(n^2), Space: O(n^2) - stack size
        self.grid = grid
        self.n, self.m = len(grid), len(grid[0])
        res = 0
        for i in range(self.n):
            for j in range(self.m):
                if self.grid[i][j] == '1':
                    self.dfs(i, j)
                    res += 1
        return res
