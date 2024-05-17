class Solution {
    final static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    int collect(int x, int y, int[][] grid, boolean[][] visited) {
        int n = grid.length;
        int m = grid[0].length;

        visited[x][y] = true;
        int res = 0;

        for (int i = 0; i < dir.length; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                continue;
            }
            if (grid[tx][ty] == 0 || visited[tx][ty]) {
                continue;
            }
            int collected = collect(tx, ty, grid, visited);
            res = Math.max(collected, res);
        }

        res += grid[x][y];
        visited[x][y] = false;

        return res;
    }

    public int getMaximumGold(int[][] grid) {
        // Backtracking - Time: O(n^2 * 4^g), Space: O(n^2)
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int collected = collect(i, j, grid, visited);
                    res = Math.max(res, collected);
                }
            }
        }

        return res;
    }
}
