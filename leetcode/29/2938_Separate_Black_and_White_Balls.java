class Solution {
    public long minimumSteps(String s) {
        // NOTE: Greedy, Two Pointers - Time: O(n), Space: O(1)
        int n = s.length();
        int leftOne = 0;
        while (leftOne < n && s.charAt(leftOne) == '0') {
            leftOne++;
        }

        long res = 0;
        int rightZero = leftOne + 1;
        while (rightZero < n) {
            while (rightZero < n && s.charAt(rightZero) == '1') {
                rightZero++;
            }
            if (rightZero < n) {
                res += rightZero - leftOne;
                leftOne++;
                rightZero++;
            }
        }
        return res;
    }
}
