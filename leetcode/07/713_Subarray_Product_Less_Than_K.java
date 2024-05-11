class Solution {
    int solve1(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        if (k <= 1) {
            return 0;
        }

        int res = 0;
        int right = 0;
        int product = 1;
        for (int left = 0 ; left < nums.length; left++) {
            while (right < nums.length && product * nums[right] < k) {
                product *= nums[right];
                right++;
            }
            if (left < right) {
                res += right - left;
                product /= nums[left];
            } else {
                product = 1;
                right = left + 1; 
            }
        }
        return res;
    }
    
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        return solve1(nums, k);
    }
}