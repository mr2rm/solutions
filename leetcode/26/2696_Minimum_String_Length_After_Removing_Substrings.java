class Solution {
    public int minLength(String s) {
        // String - Time: O(n^2), Space: O(n)
        while (s.contains("AB") || s.contains("CD")) {
            s = s.replace("AB", "");
            s = s.replace("CD", "");
        }
        return s.length();
    }
}
