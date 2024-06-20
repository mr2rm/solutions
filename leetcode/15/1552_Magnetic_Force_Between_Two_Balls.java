import java.util.Arrays;

class Solution {
    boolean check(int[] position, int m, int dist) {
        int lastPos = -dist;
        for (int x : position) {
            if (x - lastPos < dist) {
                continue;
            }
            lastPos = x;
            m--;
            if (m == 0) {
                return true;
            }
        }
        return false;
    }

    public int maxDistance(int[] position, int m) {
        // Binary Search, Sorting - Time: O(nlogN), Space: O(1)
        int n = position.length;
        Arrays.sort(position);
        int low = 1, high = position[n - 1];
        while (low < high) {
            int mid = (low + high + 1) / 2;
            boolean isValid = check(position, m, mid);
            if (isValid) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
