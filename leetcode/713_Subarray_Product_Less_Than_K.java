class Solution {
    int solve1(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        int res = 0;
        for (int i = 0, j = 0, product = 1; i < nums.length; i++) {
            while (j < nums.length && product * nums[j] < k) {
                product *= nums[j];
                j++;
            }
            if (i < j) {
                res += j - i;
                product /= nums[i];
            } else {
                j = i + 1;
                product = 1;
            }
        }
        return res;
    }
    
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        return solve1(nums, k);
    }
}