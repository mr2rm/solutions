class Solution {
    public int longestSubarray(int[] nums) {
        // Bit Manipulation - Time: O(n), Space: O(1)
        int maxVal = 0, res = 0, currentStreak = 0;
        for (int x : nums) {
            if (x > maxVal) {
                maxVal = x;
                res = currentStreak = 0;
            }

            if (x == maxVal) {
                currentStreak++;
            } else { // x < maxVal
                currentStreak = 0;
            }

            res = Math.max(res, currentStreak);
        }
        return res;
    }
}
