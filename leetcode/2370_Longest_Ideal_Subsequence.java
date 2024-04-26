class Solution {
    public int longestIdealString(String s, int k) {
        // DP - Time: O(26*n) ~ O(n), Space: O(26) ~ O(1)
        int res = 0;
        int[] dp = new int[256];

        for (char c : s.toCharArray()) {
            int start = Math.max(c - k, 'a');
            int end = Math.min(c + k, 'z');

            int cur = 0;
            for (int i = start; i <= end; i++) {
                cur = Math.max(cur, dp[i]);
            }

            dp[c] = cur + 1;
            res = Math.max(res, dp[c]);
        }

        return res;
    }
}
