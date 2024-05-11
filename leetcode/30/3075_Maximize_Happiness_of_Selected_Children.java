import java.util.Arrays;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        // Sorting, Greedy - Time: O(nlogn), Space: O(1)
        int n = happiness.length;
        Arrays.sort(happiness);

        long res = 0;
        for (int i = n - 1; i >= n - k; i--) {
            int sadness = n - i - 1;
            res += Math.max(0, happiness[i] - sadness);
        }

        return res;
    }
}
