class Solution {
    int solve1(String s) {
        // Stack, Iterative - Time: O(n), Space: O(1)
        int res = 0, depth = 0;
        for (char c: s.toCharArray()) {
            if (c == '(') {
                depth++;
                res = Math.max(res, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return res;
    }

    public int maxDepth(String s) {
        return solve1(s);
    }
}