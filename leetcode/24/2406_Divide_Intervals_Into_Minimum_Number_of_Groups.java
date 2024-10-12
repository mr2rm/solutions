import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int minGroups(int[][] intervals) {
        // Greedy, Sorting - Time: O(nlogn), Space: O(n)
        List<int[]> events = new ArrayList<>();
        for (int[] interval : intervals) {
            events.add(new int[] { interval[0], 1 });
            events.add(new int[] { interval[1] + 1, -1 });
        }

        Collections.sort(events, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int res = 0, currentIntervals = 0;
        for (int[] event : events) {
            currentIntervals += event[1];
            res = Math.max(res, currentIntervals);
        }
        return res;
    }
}
