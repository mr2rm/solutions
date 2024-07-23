import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] frequencySort(int[] nums) {
        // Sorting, Hash Table - Time: O(nlogn), Space: O(n)
        int n = nums.length;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) {
            int f = freq.getOrDefault(x, 0);
            freq.put(x, f + 1);
        }

        Integer[] numsObj = new Integer[n];
        for (int i = 0; i < n; i++) {
            numsObj[i] = nums[i];
        }

        Arrays.sort(numsObj, (a, b) -> {
            int freqA = freq.get(a);
            int freqB = freq.get(b);
            if (freqA == freqB) {
                return Integer.compare(b, a);
            }
            return Integer.compare(freqA, freqB);
        });

        for (int i = 0; i < n; i++) {
            nums[i] = numsObj[i];
        }
        return nums;
    }
}
