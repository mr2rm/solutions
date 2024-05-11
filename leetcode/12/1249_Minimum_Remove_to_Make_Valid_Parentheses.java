class Solution {
    String solve1(String s) {
        // Stack, String - Time: O(n), Space: O(n)
        int opened = 0;
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == '(') {
                opened++;
            } else if (sb.charAt(i) == ')') {
                if (opened > 0) {
                    opened--;
                } else {
                    sb.setCharAt(i, ' ');
                }
            }
        }

        for (int i = sb.length() - 1; opened > 0; i--) {
            if (sb.charAt(i) == '(') {
                sb.setCharAt(i, ' ');
                opened--;
            }
        }

        String res = sb.toString().replace(" ", "");
        return res;
    }

    public String minRemoveToMakeValid(String s) {
        return solve1(s);
    }
}
