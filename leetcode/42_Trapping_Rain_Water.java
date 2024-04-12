class Solution {
    int solve1(int[] height) {
        // Dynamic Programming - Time: O(n), Space: O(n)
        int n = height.length;

        int[] leftMax = new int[n];
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }

        int[] rightMax = new int[n];
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int level = Math.min(leftMax[i], rightMax[i]);
            res += level - height[i];
        }

        return res;
    }

    public int trap(int[] height) {
        return solve1(height);
    }
}
