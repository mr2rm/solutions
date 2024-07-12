import java.util.Stack;
import java.util.stream.Collectors;

class Solution {
    String remove(String s, String t) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            stack.add(c);
            while (stack.size() >= 2) {
                int n = stack.size();
                if (stack.get(n - 1) == t.charAt(1) && stack.get(n - 2) == t.charAt(0)) {
                    stack.pop();
                    stack.pop();
                } else {
                    break;
                }
            }
        }
        return stack.stream().map(String::valueOf).collect(Collectors.joining());
    }

    int calculatePoints(String original, String updated, int points) {
        int cnt = (original.length() - updated.length()) / 2;
        return cnt * points;
    }

    public int maximumGain(String s, int x, int y) {
        // Stack, Greed - Time: O(n), Space: O(n)
        String t1 = "ab", t2 = "ba";
        int p1 = x, p2 = y;
        if (y > x) {
            t1 = "ba";
            p1 = y;
            t2 = "ab";
            p2 = x;
        }

        String s1 = remove(s, t1);
        String s2 = remove(s1, t2);
        return calculatePoints(s, s1, p1) + calculatePoints(s1, s2, p2);
    }
}
