import java.util.Arrays;
import java.util.Stack;

class Solution {
    String s;
    int[][] dp;

    int isValidString(int start, int openCount) {
        if (start == this.s.length()) {
            if (openCount == 0) {
                return 1;
            }
            return 0;
        }

        if (this.dp[start][openCount] != -1) {
            return this.dp[start][openCount];
        }

        char c = this.s.charAt(start);
        this.dp[start][openCount] = 0;

        if (c == '(') {
            this.dp[start][openCount] = isValidString(start + 1, openCount + 1);
        } else if (c == ')') {
            if (openCount > 0) {
                this.dp[start][openCount] = isValidString(start + 1, openCount - 1);
            }
        } else {
            this.dp[start][openCount] = isValidString(start + 1, openCount);
            this.dp[start][openCount] |= isValidString(start + 1, openCount + 1);
            if (openCount > 0) {
                this.dp[start][openCount] |= isValidString(start + 1, openCount - 1);
            }
        }

        return this.dp[start][openCount];
    }

    boolean solve2(String s) {
        // Dynamic Programming (Top-Down) - Time: O(n^2), Space: O(n^2)
        int n = s.length();

        this.s = s;
        this.dp = new int[n + 1][n + 1];
        Arrays.stream(this.dp).forEach(row -> Arrays.fill(row, -1));

        return isValidString(0, 0) == 1;
    }

    boolean solve1(String s) {
        // Stack - Time: O(n), Space: O(n)
        Stack<Integer> open = new Stack<>();
        Stack<Integer> ast = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                open.push(i);
            } else if (c == '*') {
                ast.push(i);
            } else if (!open.isEmpty()) {
                open.pop();
            } else if (!ast.isEmpty()) {
                ast.pop();
            } else {
                return false;
            }
        }

        while (!open.isEmpty()) {
            if (ast.isEmpty() || ast.peek() < open.peek()) {
                return false;
            }
            open.pop();
            ast.pop();
        }

        return true;
    }

    public boolean checkValidString(String s) {
        return solve1(s);
    }
}
