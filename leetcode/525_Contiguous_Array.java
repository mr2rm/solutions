import java.util.Arrays;

class Solution {
    private int solution1(int[] nums) {
        // Prefix Sum - Time: O(n), Space: O(n)
        int n = nums.length;
        int res = 0;
        int count = 0;

        int[] indexOfCount = new int[2 * n + 1];
        Arrays.fill(indexOfCount, -2);
        indexOfCount[n] = -1;

        for (int i = 0; i < n; i++) {
            count += (nums[i] == 0 ? -1 : 1);
            if (indexOfCount[count + n] == -2) {
                indexOfCount[count + n] = i;
            } else {
                res = Math.max(res, i - indexOfCount[count + n]);
            }
        }
        return res;
    }

    public int findMaxLength(int[] nums) {
        return this.solution1(nums);
    }
}