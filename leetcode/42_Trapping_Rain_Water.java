class Solution {
    int solve2(int[] height) {
        // Divide and Conquer - Time: O(n), Space: O(1)
        int n = height.length;
        int res = 0;

        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] > height[maxIndex]) {
                maxIndex = i;
            }
        }

        int leftMax = 0;
        for (int i = 0; i < maxIndex; i++) {
            leftMax = Math.max(leftMax, height[i]);
            res += leftMax - height[i];
        }

        int rightMax = 0;
        for (int i = n - 1; i > maxIndex; i--) {
            rightMax = Math.max(rightMax, height[i]);
            res += rightMax - height[i];
        }

        return res;
    }

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
        return solve2(height);
    }
}
