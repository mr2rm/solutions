import java.util.List;
import java.util.ArrayList;

class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        // Brute Force, Sorting - Time: O(n^2 * log n^2), Space: O(n^2)
        List<Integer> sumList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sumList.add(sum);
            }
        }
        sumList.sort((a, b) -> Integer.compare(a, b));

        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res += sumList.get(i);
            res %= 1_000_000_007;
        }
        return res;
    }
}
