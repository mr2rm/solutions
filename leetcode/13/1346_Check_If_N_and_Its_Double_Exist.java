import java.util.HashSet;
import java.util.Set;

class Solution {
    /**
     * Adhoc, Array - Time: O(n^2), Space: O(1)
     * 
     * @param arr Array of integers
     * @return Whether there are i and j indices that arr[i] == 2 * arr[j]
     */
    private boolean solve1(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }


    /**
     * Set - Time: O(n), Space: O(n)
     * 
     * @param arr Array of integers
     * @return Whether there are i and j indices that arr[i] == 2 * arr[j]
     */
    private boolean solve2(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int x : arr) {
            if (set.contains(2 * x)) {
                return true;
            }
            if (x % 2 == 0 && set.contains(x / 2)) {
                return true;
            }
            set.add(x);
        }
        return false;

    }

    public boolean checkIfExist(int[] arr) {
        return solve2(arr);
    }
}
