class Solution {
    int n;
    int m;
    int[][] grid1;
    int[][] grid2;
    boolean[][] visited;
    final int[][] dir = {
            { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 },
    };

    boolean isSubIsland(int x, int y) {
        visited[x][y] = true;
        boolean ret = (grid1[x][y] == 1);

        for (int i = 0; i < dir.length; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid2[tx][ty] == 1 && !visited[tx][ty]) {
                ret &= isSubIsland(tx, ty);
            }
        }
        return ret;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        // DFS, Flood Fill - Time: O(n*m), Space: O(n*m
        n = grid2.length;
        m = grid2[0].length;
        this.grid1 = grid1;
        this.grid2 = grid2;
        visited = new boolean[n][m];

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j] && isSubIsland(i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
}
