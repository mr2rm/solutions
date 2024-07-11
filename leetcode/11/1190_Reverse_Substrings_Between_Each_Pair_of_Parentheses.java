import java.util.Stack;

class Solution {
    public String reverseParentheses(String s) {
        // String, Stack - Time: O(n^2), Space: O(n)
        Stack<Character> stack = new Stack<>();
        StringBuilder res = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c != ')') {
                if (c == '(' || !stack.isEmpty()) {
                    stack.add(c);
                } else {
                    res.append(c);
                }
                continue;
            }

            StringBuilder sb = new StringBuilder();
            while (stack.peek() != '(') {
                sb.append(stack.pop());
            }
            stack.pop();

            if (stack.isEmpty()) {
                res.append(sb);
                continue;
            }

            while (!sb.isEmpty()) {
                stack.add(sb.charAt(0));
                sb.deleteCharAt(0);
            }
        }

        return res.toString();
    }
}
