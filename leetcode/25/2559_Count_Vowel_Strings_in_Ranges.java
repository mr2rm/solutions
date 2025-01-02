class Solution {
    final static String vowels = "aeiou";

    private boolean isVowelString(String s) {
        int n = s.length();
        if (vowels.indexOf(s.charAt(0)) == -1 || vowels.indexOf(s.charAt(n - 1)) == -1) {
            return false;
        }
        return true;
    }

    public int[] vowelStrings(String[] words, int[][] queries) {
        // String, Prefix Sum - Time: O(n * m), Space: O(n)
        int n = words.length;
        int m = queries.length;

        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            if (isVowelString(words[i])) {
                prefixSum[i + 1]++;
            }
        }

        int[] results = new int[m];
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            results[i] = prefixSum[r + 1] - prefixSum[l];
        }
        return results;
    }
}
