class Solution {
    public char findKthBit(int n, int k) {
        // NOTE: Recursion - Time: O(n), Space: O(n)
        if (n == 1) {
            return '0';
        }

        int len = (int) Math.pow(2, n) - 1;
        int mid = (len + 1) / 2;
        if (k == mid) {
            return '1';
        }

        if (k < mid) {
            return findKthBit(n - 1, k);
        }
        int d = '1' - findKthBit(n - 1, len - k + 1);
        return (char) ('0' + d);
    }
}
