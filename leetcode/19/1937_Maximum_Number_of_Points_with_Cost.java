class Solution {
    public long maxPoints(int[][] points) {
        // DP - Time: O(n * m), Space: O(m)
        int n = points.length;
        int m = points[0].length;

        long[] dp = new long[m];
        for (int j = 0; j < m; j++) {
            dp[j] = points[0][j];
        }

        for (int i = 1; i < n; i++) {
            long[] leftMax = new long[m];
            leftMax[0] = dp[0];
            for (int j = 1; j < m; j++) {
                leftMax[j] = Math.max(leftMax[j - 1] - 1, dp[j]);
            }

            long[] rightMax = new long[m];
            rightMax[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                rightMax[j] = Math.max(rightMax[j + 1] - 1, dp[j]);
            }

            for (int j = 0; j < m; j++) {
                dp[j] = Math.max(leftMax[j], rightMax[j]) + points[i][j];
            }
        }

        long res = dp[0];
        for (int j = 1; j < m; j++) {
            res = Math.max(res, dp[j]);
        }

        return res;
    }
}
