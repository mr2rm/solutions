class Solution {
    @SuppressWarnings("unused")
    private boolean solve1(int[] nums) {
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

    private boolean solve2(int[] nums) {
        // Greedy - Time: O(n), Space: O(1)
        int n = nums.length;
        int goal = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }

    public boolean canJump(int[] nums) {
        return solve2(nums);
    }
}
