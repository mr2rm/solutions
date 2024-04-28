import java.util.Arrays;

class Solution {
    int dist(String ring, int from, int to) {
        int l = Math.min(from, to);
        int r = Math.max(from, to);
        return Math.min(r - l, ring.length() - r + l);
    }

    int solve(int k, int r, String key, String ring, int[][] dp) {
        if (k == key.length()) {
            return 0;
        }

        if (dp[k][r] != -1) {
            return dp[k][r];
        }

        dp[k][r] = Integer.MAX_VALUE;
        for (int i = 0; i < ring.length(); i++) {
            if (key.charAt(k) == ring.charAt(i)) {
                int res = solve(k + 1, i, key, ring, dp) + dist(ring, r, i) + 1;
                dp[k][r] = Math.min(dp[k][r], res);
            }
        }

        return dp[k][r];
    }

    public int findRotateSteps(String ring, String key) {
        // Top-Down DP - Time: O(n * m^2), Space: O(n^2)
        int n = key.length();
        int m = ring.length();

        int[][] dp = new int[n][m];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, key, ring, dp);
    }
}
