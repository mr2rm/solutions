class Solution {
    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    int dfs(int x, int y, boolean[][] mark, int[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) {
            return 1;
        }

        if (mark[x][y]) {
            return 0;
        }

        mark[x][y] = true;
        int res = 0;

        for (int i = 0; i < Solution.dir.length; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            res += dfs(tx, ty, mark, grid);
        }
        return res;
    }

    public int islandPerimeter(int[][] grid) {
        // DFS, Flood Fill - Time: O(n^2), Space: O(n^2)
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] mark = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, mark, grid);
                }
            }
        }

        return 0;
    }
}
