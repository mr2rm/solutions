class Solution {
    public void reverseString(char[] s) {
        // String - Time: O(n), Space: O(1)
        int n = s.length;
        for (int i = 0; i < n / 2; i++) {
            int j = n - i - 1;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
}
