class Solution {
    int solve(int i, int xor, int[] nums) {
        if (i == nums.length) {
            return xor;
        }

        int ret = 0;
        ret += solve(i + 1, nums[i] ^ xor, nums);
        ret += solve(i + 1, xor, nums);
        return ret;
    }

    public int subsetXORSum(int[] nums) {
        // Backtracking, Bit Manipulation - Time: O(2^n), Space: O(n)
        return solve(0, 0, nums);
    }
}
