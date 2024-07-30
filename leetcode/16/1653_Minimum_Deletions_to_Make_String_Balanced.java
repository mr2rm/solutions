class Solution {
    public int minimumDeletions(String s) {
        // DP, Prefix Sum - Time: O(n), Space: O(n)
        int n = s.length();

        int[] prefixB = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixB[i] = prefixB[i - 1];
            if (s.charAt(i - 1) == 'b') {
                prefixB[i]++;
            }
        }

        int[] suffixA = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            suffixA[i] = suffixA[i + 1];
            if (s.charAt(i) == 'a') {
                suffixA[i]++;
            }
        }

        int res = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            res = Math.min(res, prefixB[i] + suffixA[i]);
        }
        return res;
    }
}
