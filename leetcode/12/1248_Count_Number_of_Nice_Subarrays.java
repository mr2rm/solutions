import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        // Prefix Sum, Hash Table - Time: O(n), Space: O(n)
        Map<Integer, Integer> prefixSum = new HashMap<>();
        prefixSum.put(0, 1);

        int currentSum = 0, res = 0;
        for (int x : nums) {
            currentSum += x % 2;

            int count = prefixSum.getOrDefault(currentSum, 0);
            prefixSum.put(currentSum, count + 1);

            res += prefixSum.getOrDefault(currentSum - k, 0);
        }

        return res;
    }
}
