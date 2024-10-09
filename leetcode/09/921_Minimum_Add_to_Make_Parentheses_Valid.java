import java.util.Stack;

class Solution {
    int solution1(String s) {
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

    int solution2(String s) {
        // Greedy - Time: O(n), Space: O(1)
        int opened = 0, res = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                opened++;
            } else if (opened > 0) {
                opened--;
            } else {
                res++;
            }
        }
        res += opened;
        return res;
    }

    public int minAddToMakeValid(String s) {
        return solution2(s);
    }
}
