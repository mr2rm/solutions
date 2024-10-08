import java.util.Stack;

class Solution {
    int solution1(String s) {
        // Greedy, Stack - Time: O(n), Space: O(n)
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

    int solution2(String s) {
        // Greedy - Time: O(n), Space: O(1)
        int unbalanced = 0;
        int opened = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                opened++;
            } else if (opened > 0) {
                opened--;
            } else {
                unbalanced++;
            }
        }

        int res = (unbalanced + 1) / 2;
        return res;
    }

    public int minSwaps(String s) {
        return solution2(s);
    }
}
