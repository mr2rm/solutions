class Solution {
    int n;

    int solve(int curr, int clipboard, int[][] memo) {
        if (curr > this.n) {
            return 1_000_000;
        }
        if (curr == this.n) {
            return 0;
        }

        if (memo[curr][clipboard] != 0) {
            return memo[curr][clipboard];
        }

        int pasteOnly = solve(curr + clipboard, clipboard, memo) + 1;
        int copyAndPaste = solve(curr * 2, curr, memo) + 2;
        memo[curr][clipboard] = Math.min(pasteOnly, copyAndPaste);
        return memo[curr][clipboard];
    }

    public int minSteps(int n) {
        // DP, Top Down - Time: O(n^2), Space: (n^2)
        if (n == 1) {
            return 0;
        }

        this.n = n;
        int[][] memo = new int[n + 1][n / 2 + 1];
        return 1 + solve(1, 1, memo);
    }
}
