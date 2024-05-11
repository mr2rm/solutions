from typing import List


class Solution:
    def get_min_point(self, x: int, y: int) -> int:
        res = 1
        if self.mat[x][y] <= 0:
            res += abs(self.mat[x][y])
        return res

    def solve(self, x: int, y: int) -> int:
        if x == len(self.mat) or y == len(self.mat[0]):
            return float('inf')
        if self.dp[x][y] is not None:
            return self.dp[x][y]

        min_point = self.get_min_point(x, y)
        current_point = min_point + self.mat[x][y]
        next_point = min(self.solve(x + 1, y), self.solve(x, y + 1))
        self.dp[x][y] = min_point + max(next_point - current_point, 0)
        return self.dp[x][y]

    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        # DP - Time: O(n^2), Space: O(n^2)
        self.mat = dungeon
        n, m = len(dungeon), len(dungeon[0])
        self.dp = [[None] * m for _ in range(n)]
        self.dp[n - 1][m - 1] = self.get_min_point(n - 1, m - 1)
        res = self.solve(0, 0)
        return res
