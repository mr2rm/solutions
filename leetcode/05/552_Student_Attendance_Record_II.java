class Solution {
    private static final int M = 1_000_000_007;
    static int n;
    static int[][][] dp = new int[100_010][2][3];

    int solve(int i, int absents, int lates) {
        if (absents >= 2 || lates >= 3) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (dp[i][absents][lates] != -1) {
            return dp[i][absents][lates];
        }

        dp[i][absents][lates] = solve(i + 1, absents + 1, 0);
        dp[i][absents][lates] %= M;

        dp[i][absents][lates] += solve(i + 1, absents, lates + 1);
        dp[i][absents][lates] %= M;

        dp[i][absents][lates] += solve(i + 1, absents, 0);
        dp[i][absents][lates] %= M;

        return dp[i][absents][lates];
    }

    public int checkRecord(int n) {
        // DP - Time: O(n), Space: O(n)

        Solution.n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        return solve(0, 0, 0);
    }
}
