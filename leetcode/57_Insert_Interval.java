import java.util.ArrayList;
import java.lang.Math;

class Solution {
    int[][] solution1(int[][] intervals, int[] newInterval) {
        // Array - Time: O(n), Space: O(n)
        int n = intervals.length;
        ArrayList<int[]> res = new ArrayList<>();
        int[] interval = new int[2];

        int i = 0;
        for (; i < n && intervals[i][1] < newInterval[0]; i++) {
            res.add(intervals[i]);
        }
        interval[0] = newInterval[0];
        if (i < n) {
            interval[0] = Math.min(intervals[i][0], newInterval[0]);
        }

        for (; i < n && intervals[i][1] < newInterval[1]; i++)
            ;
        interval[1] = newInterval[1];
        if (i < n && intervals[i][0] <= newInterval[1]) {
            interval[1] = intervals[i][1];
            i++;
        }

        res.add(interval);
        for (; i < n; i++) {
            res.add(intervals[i]);
        }
        return res.toArray(new int[res.size()][]);
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {
        return this.solution1(intervals, newInterval);
    }
}
