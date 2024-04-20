class Solution {
    static int[][] dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    void dfs(char[][] grid, boolean[][] visited, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
            return;
        }

        if (grid[x][y] == '0' || visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        for (int i = 0; i < Solution.dir.length; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            dfs(grid, visited, tx, ty);
        }
    }

    public int numIslands(char[][] grid) {
        // DFS, Flood Fill - Time: O(n^2), Space: O(n^2)
        int n = grid.length;
        int m = grid[0].length;
        boolean visited[][] = new boolean[n][m];

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    res += 1;
                }
            }
        }
        return res;
    }
}
