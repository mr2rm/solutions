import java.util.Stack;

class Solution {
    public int minSwaps(String s) {
        // Stack - Time: O(n), Space: O(n)
        int unbalanced = 0;
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '[') {
                stack.push(c);
            } else if (!stack.isEmpty()) {
                stack.pop();
            } else {
                unbalanced++;
            }
        }

        int res = (unbalanced + 1) / 2;
        return res;
    }
}
