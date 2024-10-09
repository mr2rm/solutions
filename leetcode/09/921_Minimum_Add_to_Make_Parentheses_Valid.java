import java.util.Stack;

class Solution {
    public int minAddToMakeValid(String s) {
        // Stack, Greedy - Time: O(n), Space: O(n)
        int res = 0;
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(c);
            } else if (!stack.isEmpty()) {
                stack.pop();
            } else {
                res++;
            }
        }

        res += stack.size();
        return res;
    }
}
