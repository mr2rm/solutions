import java.util.Stack;

class Solution {
    public int maxWidthRamp(int[] nums) {
        // Monotonic Stack, Greedy - Time: O(n), Space: O(n)
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[] { nums[0], 0 });
        for (int i = 1; i < nums.length; i++) {
            int[] top = stack.peek();
            if (nums[i] < top[0]) {
                stack.push(new int[] { nums[i], i });
            }
        }

        int res = 0, i = nums.length - 1;
        while (!stack.isEmpty()) {
            int[] top = stack.peek();
            if (top[0] <= nums[i]) {
                res = Math.max(res, i - top[1]);
                stack.pop();
            } else {
                i--;
            }
        }
        return res;
    }
}
