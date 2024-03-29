import java.lang.Math;

class Solution {
    int findMaxElement(int[] nums) {
        int res = nums[0];
        for (int x: nums) {
            res = Math.max(res, x);
        }
        return res;
    }

    long solve1(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        int max = findMaxElement(nums);
        long res = 0;
        int cnt = 0;
        int end = 0;
        for (int start = 0; start < nums.length; start++) {
            for (; end < nums.length && cnt < k; end++) {
                if (nums[end] == max) {
                    cnt++;
                }
            }
            if (cnt == k) {
                res += nums.length - end + 1;
            }
            if (nums[start] == max) {
                cnt--;
            }
        }
        return res;
    }

    public long countSubarrays(int[] nums, int k) {
        return solve1(nums, k);
    }
}