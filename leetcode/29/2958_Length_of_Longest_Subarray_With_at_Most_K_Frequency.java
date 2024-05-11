import java.util.HashMap;

class Solution {
    int solve1(int[] nums, int k) {
        // Sliding Window, Hash Table - Time: O(n), Space: O(n)
        int res = 0;
        int right = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int left = 0; left < nums.length; left++) {
            for (; right < nums.length && map.getOrDefault(nums[right], 0) < k; right++) {
                int count = map.getOrDefault(nums[right], 0);
                map.put(nums[right], count + 1);
            }
            res = Math.max(res, right - left);
            map.put(nums[left], map.get(nums[left]) - 1);
        }
        return res;
    }

    public int maxSubarrayLength(int[] nums, int k) {
        return this.solve1(nums, k);
    }
}