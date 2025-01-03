class Solution {
    public int waysToSplitArray(int[] nums) {
        // Prefix Sum - Time: O(n), Space: O(n)
        int n = nums.length;

        long[] prefixSum = new long[n];
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            long leftSum = prefixSum[i];
            long rightSum = prefixSum[n - 1] - prefixSum[i];
            if (leftSum >= rightSum) {
                result++;
            }
        }
        return result;
    }
}
