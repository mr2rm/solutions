class Solution {
    int[][] memo;

    String removeDuplicates(String s) {
        StringBuilder res = new StringBuilder();
        res.append(s.charAt(0));

        for (int i = 1; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (curr != s.charAt(i - 1)) {
                res.append(curr);
            }
        }
        return res.toString();
    }

    int minTurn(String s, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (this.memo[start][end] != 0) {
            return this.memo[start][end];
        }

        int res = 1 + minTurn(s, start + 1, end);
        for (int i = start + 1; i <= end; i++) {
            if (s.charAt(i) == s.charAt(start)) {
                int turns = minTurn(s, start, i - 1) + minTurn(s, i + 1, end);
                res = Math.min(res, turns);
            }
        }

        this.memo[start][end] = res;
        return res;
    }

    public int strangePrinter(String s) {
        // Dynamic Programming - Time: O(n^3), Space: O(n^2)
        s = removeDuplicates(s);
        int n = s.length();
        this.memo = new int[n][n];

        return minTurn(s, 0, n - 1);
    }
}
