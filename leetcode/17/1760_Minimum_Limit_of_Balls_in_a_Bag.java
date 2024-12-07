class Solution {
    private static boolean isPossible(int[] nums, int operations, int penalty) {
        for (int x : nums) {
            int requiredOperations = x / penalty;
            if (x % penalty == 0) {
                requiredOperations--;
            }

            operations -= requiredOperations;
            if (operations < 0) {
                return false;
            }
        }
        return true;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        // Binary Search - Time: O(nlogm), Space: O(1)
        int low = 1, high = 1_000_000_000;
        while (low < high) {
            int mid = (low + high) / 2;
            boolean possible = isPossible(nums, maxOperations, mid);
            if (possible) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
