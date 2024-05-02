import java.util.Arrays;

class Solution {
    int solve1(int[] nums) {
        // Two Pointers - Time: O(nlogn), Space: O(1)
        Arrays.sort(nums);
        int l = 0;
        int r = nums.length - 1;
        while (nums[l] < 0 && nums[r] > 0) {
            if (Math.abs(nums[l]) == nums[r]) {
                return nums[r];
            }

            if (Math.abs(nums[l]) < nums[r]) {
                r--;
            } else {
                l++;
            }
        }
        return -1;
    }

    public int findMaxK(int[] nums) {
        return solve1(nums);
    }
}
