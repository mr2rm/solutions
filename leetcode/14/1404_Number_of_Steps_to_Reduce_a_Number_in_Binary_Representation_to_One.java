class Solution {
    public int numSteps(String s) {
        // Bit Manipulation - Time: O(n) - Space: O(1)
        int res = 0;

        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == '0') {
            res++;
            i--;
        }

        if (i == 0) {
            return res;
        }

        while (i >= 0) {
            int j = i - 1;
            while (j >= 0 && s.charAt(j) == '1') {
                j--;
            }

            res += (i - j) + 1;
            i = j;
        }
        return res;
    }
}
