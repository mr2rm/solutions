import java.util.Arrays;
import java.util.List;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        // String, Sorting, Array - Time: O(nlogn), Space: O(n)
        int n = timePoints.size();

        int[] minutes = new int[n];
        for (int i = 0; i < n; i++) {
            String time = timePoints.get(i);
            int h = Integer.parseInt(time.substring(0, 2));
            int m = Integer.parseInt(time.substring(3));
            minutes[i] = h * 60 + m;
        }

        Arrays.sort(minutes);

        int res = (24 * 60 - minutes[n - 1]) + minutes[0];
        for (int i = 1; i < n; i++) {
            res = Math.min(res, minutes[i] - minutes[i - 1]);
        }
        return res;
    }
}
