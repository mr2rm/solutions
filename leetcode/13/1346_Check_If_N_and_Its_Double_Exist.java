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
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean checkIfExist(int[] arr) {
        return solve1(arr);
    }
}
