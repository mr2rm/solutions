import java.util.Stack;

class Solution {
    String solve1(String s) {
        // Stack - Time: O(n), Space: O(n)
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            stack.push(c);
            while (stack.size() >= 2) {
                char a = stack.pop();
                char b = stack.pop();
                if (a != b && Character.toLowerCase(a) == Character.toLowerCase(b)) {
                    continue;
                }
                stack.push(b);
                stack.push(a);
                break;
            }
        }

        String res = "";
        while (!stack.isEmpty()) {
            res = stack.pop() + res;
        }
        return res;
    }

    public String makeGood(String s) {
        return solve1(s);
    }
}
