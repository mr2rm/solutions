class Solution {
    boolean checkDay(int[] bloomDay, int m, int k, int d) {
        int blooms = 0;
        int count = 0;

        for (int x : bloomDay) {
            if (x > d) {
                blooms = 0;
            } else {
                blooms++;
            }
            if (blooms == k) {
                blooms = 0;
                count++;
            }
        }

        return count >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        // Binary Search - Time: O(nlogN), Space: O(1)
        final int N = 1_000_000_001;
        int low = 1, high = N;
        while (low < high) {
            int mid = (low + high) / 2;
            boolean isPossible = checkDay(bloomDay, m, k, mid);
            if (!isPossible) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low == N) {
            return -1;
        }
        return low;
    }
}
