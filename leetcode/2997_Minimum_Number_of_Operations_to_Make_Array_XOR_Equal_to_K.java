class Solution {
    public int minOperations(int[] nums, int k) {
        // Bit Manipulation - Time: O(n), Space: (1)
        int diffMask = k;
        for (int x : nums) {
            diffMask ^= x;
        }

        int res = 0;
        while (diffMask != 0) {
            res += 1;
            diffMask &= (diffMask - 1);
        }

        return res;
    }
}
