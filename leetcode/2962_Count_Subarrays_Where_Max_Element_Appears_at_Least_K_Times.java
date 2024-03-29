import java.lang.Math;
import java.util.Arrays;

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

    long solve2(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        int start = 0;
        int max_number = Arrays.stream(nums).max().getAsInt();
        int max_number_freq = 0;
        int res = 0;

        for (int end = 0; end < nums.length; end++) {
            if (nums[end] == max_number) {
                max_number_freq++;
            }
            for (; max_number_freq == k; start++) {
                if (nums[start] == max_number) {
                    max_number_freq--;
                }
            }
            res += start;
        }

        return res;
    }

    public long countSubarrays(int[] nums, int k) {
        return solve2(nums, k);
    }
}