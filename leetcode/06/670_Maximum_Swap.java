class Solution {
    public int maximumSwap(int num) {
        // NOTE: Math, Greedy - Time: O(n^2), Space: O(n)
        char[] digits = Integer.toString(num).toCharArray();
        int n = digits.length;

        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) {
                if (digits[j] >= digits[k]) {
                    k = j;
                }
            }

            if (digits[k] > digits[i]) {
                char temp = digits[i];
                digits[i] = digits[k];
                digits[k] = temp;
                break;
            }
        }

        return Integer.valueOf(String.valueOf(digits));
    }
}
