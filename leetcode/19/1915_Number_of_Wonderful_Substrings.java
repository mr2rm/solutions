class Solution {
    public long wonderfulSubstrings(String word) {
        // Bit Manipulation, Bitmask, DP - Time: O(n), Space: O(2^10)
        int[] dp = new int[1024];
        dp[0] = 1;

        long res = 0;
        int repr = 0;
        for (char c : word.toCharArray()) {
            int mask = 1 << (c - 'a');
            repr ^= mask;

            // substrings with even frequency
            res += dp[repr];

            // substrings with only 1 odd frequency
            for (int i = 0; i < 10; i++) {
                int flipped = repr ^ (1 << i);
                res += dp[flipped];
            }

            dp[repr]++;
        }

        return res;
    }
}
