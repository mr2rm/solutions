class Solution {
    String solve1(String num, int k) {
        // Greedy, Monothonic Stack - Time: O(n), Space: O(n)
        if (k >= num.length()) {
            return "0";
        }

        StringBuilder builder = new StringBuilder();
        for (char c : num.toCharArray()) {
            while (k > 0 && !builder.isEmpty() && c < builder.charAt(builder.length() - 1)) {
                builder.deleteCharAt(builder.length() - 1);
                k--;
            }
            builder.append(c);
        }

        builder.delete(builder.length() - k, builder.length());
        String res = builder.toString().replaceFirst("^0+", "");
        return res.isEmpty() ? "0" : res;
    }

    public String removeKdigits(String num, int k) {
        return solve1(num, k);
    }
}
