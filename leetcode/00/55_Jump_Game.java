class Solution {
    public boolean canJump(int[] nums) {
        // DP - Time: O(n^2), Space: O(n)
        int n = nums.length;
        boolean[] isPossible = new boolean[n];
        isPossible[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            int maxJump = Math.min(n - 1, i + nums[i]);
            for (int j = i + 1; j <= maxJump; j++) {
                if (isPossible[j]) {
                    isPossible[i] = true;
                    break;
                }
            }
        }
        return isPossible[0];
    }
}
