import java.util.Stack;

class Solution {
    int solution1(String s) {
        // String - Time: O(n^2), Space: O(n)
        while (s.contains("AB") || s.contains("CD")) {
            s = s.replace("AB", "");
            s = s.replace("CD", "");
        }
        return s.length();
    }

    int solution2(String s) {
        // Stack - Time: O(n), Space: O(n)
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (stack.isEmpty()) {
                stack.push(c);
                continue;
            }

            // if ((c == 'B' && stack.peek() == 'A') || (c == 'D' && stack.peek() == 'C')) {
            if ((c == 'B' || c == 'D') && stack.peek() == c - 1) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.size();
    }

    public int minLength(String s) {
        return solution2(s);
    }
}
