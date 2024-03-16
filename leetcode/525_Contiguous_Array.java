import java.util.Arrays;
import java.util.HashMap;

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

    private int solution2(int[] nums) {
        // Prefix Sum, Hash Table - Time: O(n), Space: O(n)
        int res = 0;
        int count = 0;

        HashMap<Integer, Integer> indexOfCount = new HashMap<>();
        indexOfCount.put(0, -1);

        for (int i = 0; i < nums.length; i++) {
            count += (nums[i] == 0 ? -1 : 1);
            if (indexOfCount.containsKey(count)) {
                res = Math.max(res, i - indexOfCount.get(count));
            } else {
                indexOfCount.put(count, i);
            }
        }
        return res;
    }

    public int findMaxLength(int[] nums) {
        return this.solution2(nums);
    }
}