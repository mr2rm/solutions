class Solution {
    public int countTriplets(int[] arr) {
        // Bit Manipulation - Time: O(n^3), Space: O(n)
        int n = arr.length;

        int[] pre_xor = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pre_xor[i] = pre_xor[i - 1] ^ arr[i - 1];
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    int a = pre_xor[j - 1] ^ pre_xor[i - 1];
                    int b = pre_xor[k] ^ pre_xor[j - 1];
                    if (a == b) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
}
