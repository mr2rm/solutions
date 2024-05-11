class Solution {
    long solve1(int[] nums, int minK, int maxK) {
        // Sliding Window - Time: O(n), Space: O(1)
        int minFreq, maxFreq;
        minFreq = maxFreq = 0;
        long res, currCount;
        res = currCount = 0;

        int start = 0;
        for (int end = 0; end < nums.length; end++) {
            if (nums[end] < minK || nums[end] > maxK) {
                currCount = minFreq = maxFreq = 0;
                start = end + 1;
                continue;
            }
           
            if (nums[end] == minK) minFreq++;
            if (nums[end] == maxK) maxFreq++;

            for (; minFreq > 0 && maxFreq > 0; start++) {
                if (nums[start] == minK) minFreq--;
                if (nums[start] == maxK) maxFreq--;
                currCount++;
            }
            res += currCount;
        }

        return res;
    }

    public long countSubarrays(int[] nums, int minK, int maxK) {
        return solve1(nums, minK, maxK);
    }
}