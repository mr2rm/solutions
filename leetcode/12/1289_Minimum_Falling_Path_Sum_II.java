class Solution {
    public int minFallingPathSum(int[][] grid) {
        // DP - Time: O(n^3), Space: O(n^2)
        int n = grid.length;
        int[][] dp = new int[n][n];
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = 0; k < n; k++) {
                    if (j == k)
                        continue;
                    dp[i][j] = Math.min(dp[i - 1][k] + grid[i][j], dp[i][j]);
                }
            }
        }

        int res = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            res = Math.min(dp[n - 1][j], res);
        }
        return res;
    }
}
