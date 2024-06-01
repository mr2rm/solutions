class Solution {
    public int scoreOfString(String s) {
        // String - Time: O(n), Space: O(1)
        int res = 0;
        for (int i = 1; i < s.length(); i++) {
            int diff = s.charAt(i) - s.charAt(i - 1);
            res += Math.abs(diff);
        }
        return res;
    }
}
