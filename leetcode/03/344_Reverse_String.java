class Solution {
    void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    void solve1(char[] s) {
        // String - Time: O(n), Space: O(1)
        int n = s.length;
        for (int i = 0; i < n / 2; i++) {
            swap(s, i, n - i - 1);
        }
    }

    void solve2(char[] s) {
        // Two Pointers - Time: O(n), Space: O(1)
        int l = 0;
        int r = s.length - 1;
        while (l < r) {
            swap(s, l, r);
            l++;
            r--;
        }
    }

    public void reverseString(char[] s) {
        solve2(s);
    }
}
