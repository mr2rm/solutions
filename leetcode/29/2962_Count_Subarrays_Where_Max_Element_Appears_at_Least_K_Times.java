import java.lang.Math;
import java.util.Arrays;

class Solution {
    long solve1(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        int max_number = Arrays.stream(nums).max().getAsInt();
        int max_number_freq = 0;
        int end = 0;
        long res = 0;

        for (int start = 0; start < nums.length; start++) {
            for (; end < nums.length && max_number_freq < k; end++) {
                if (nums[end] == max_number) {
                    max_number_freq++;
                }
            }
            if (max_number_freq == k) {
                res += nums.length - end + 1;
            }
            if (nums[start] == max_number) {
                max_number_freq--;
            }
        }
        return res;
    }

    long solve2(int[] nums, int k) {
        // Sliding Window - Time: O(n), Space: O(1)
        int max_number = Arrays.stream(nums).max().getAsInt();
        int max_number_freq = 0;
        int start = 0;
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