import java.util.Stack;

class Solution {
    boolean areBadNeighbors(char a, char b) {
        return a != b && Character.toLowerCase(a) == Character.toLowerCase(b);
    }

    int findBadNeighbors(StringBuilder sb) {
        for (int i = 0; i + 1 < sb.length(); i++) {
            char a = sb.charAt(i);
            char b = sb.charAt(i + 1);
            if (areBadNeighbors(a, b))
                return i;
        }

        return -1;
    }

    String solve3(String s) {
        // Stack, String - Time: O(n), Space: O(n)
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (!sb.isEmpty() && areBadNeighbors(c, sb.charAt(sb.length() - 1))) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }

    String solve2(String s) {
        // Brute Force - Time: O(n^2), Space: O(1)
        StringBuilder sb = new StringBuilder(s);

        while (true) {
            int i = findBadNeighbors(sb);
            if (i == -1)
                break;

            sb.deleteCharAt(i);
            sb.deleteCharAt(i);
        }

        return sb.toString();
    }

    String solve1(String s) {
        // Stack - Time: O(n), Space: O(n)
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && areBadNeighbors(c, stack.peek())) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        String res = "";
        while (!stack.isEmpty()) {
            res = stack.pop() + res;
        }
        return res;
    }

    public String makeGood(String s) {
        return solve3(s);
    }
}
