class Solution {
    public int appendCharacters(String s, String t) {
        // Greedy, Two Pointers - Time: O(n), Space: O(1)
        int n = s.length(), i = 0;
        int m = t.length(), j = 0;
        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                j++;
            }
            i++;
        }
        return m - j;
    }
}
