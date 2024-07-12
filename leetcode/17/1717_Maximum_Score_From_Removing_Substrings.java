import java.util.Stack;

class Solution {
    String remove(String s, String t) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == t.charAt(1) && !stack.isEmpty() && stack.peek() == t.charAt(0)) {
                stack.pop();
            } else {
                stack.add(c);
            }
        }

        // return stack.stream().map(String::valueOf).collect(Collectors.joining());
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.reverse().toString();
    }

    int calculatePoints(String original, String updated, int points) {
        int cnt = (original.length() - updated.length()) / 2;
        return cnt * points;
    }

    public int maximumGain(String s, int x, int y) {
        // Stack, Greed - Time: O(n), Space: O(n)
        int res = 0;

        String t1 = x > y ? "ab" : "ba";
        String s1 = remove(s, t1);
        res += calculatePoints(s, s1, Math.max(x, y));

        String t2 = x > y ? "ba" : "ab";
        String s2 = remove(s1, t2);
        res += calculatePoints(s1, s2, Math.min(x, y));

        return res;
    }
}
