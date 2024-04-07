import java.util.Stack;

class Solution {
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
