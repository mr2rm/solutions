class Solution {
    public int maxScore(String s) {
        // Prefix Sum - Time: O(n), Space: O(n)
        int n = s.length();
        int[] prefixSum = new int[n];
        for (int i = 0; i < n; i++) {
            int value = s.charAt(i) - '0';
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + value;
        }

        int maxScore = 0;
        for (int i = 0; i < n - 1; i++) {
            int score = (i + 1 - prefixSum[i]) + (prefixSum[n - 1] - prefixSum[i]);
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}

