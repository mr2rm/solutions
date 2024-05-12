class Solution {
    final static int[][] dir = {
            { -1, -1 }, { -1, 0 }, { -1, 1 },
            { 0, -1 }, { 0, 0 }, { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 },
    };

    public int[][] largestLocal(int[][] grid) {
        // Array, Iterative - Time: O(n^2), Space(n^2)
        int n = grid.length;
        int[][] res = new int[n - 2][n - 2];

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                for (int k = 0; k < 9; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    res[i - 1][j - 1] = Math.max(res[i - 1][j - 1], grid[x][y]);
                }
            }
        }
        return res;
    }
}
