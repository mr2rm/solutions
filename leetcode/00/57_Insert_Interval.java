import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
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

    int[][] solution2(int[][] intervals, int[] newInterval) {
        // Array, Sorting - Time: O(nlogn), Space: O(n)
        ArrayList<int[]> arr = new ArrayList<>(Arrays.asList(intervals));
        arr.add(newInterval);
        arr.sort(Comparator.comparingInt(a -> a[0]));

        ArrayList<int[]> res = new ArrayList<>();
        res.add(arr.get(0));
        for (int i = 1; i < arr.size(); i++) {
            int[] thisInterval = arr.get(i);
            int lastIndex = res.size() - 1;
            int[] lastInterval = res.get(lastIndex);
            if (thisInterval[0] > lastInterval[1]) {
                res.add(thisInterval);
                continue;
            }

            res.remove(lastIndex);
            lastInterval[1] = Math.max(lastInterval[1], thisInterval[1]);
            res.add(lastInterval);
        }
        return res.toArray(new int[res.size()][]);
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {
        return this.solution2(intervals, newInterval);
    }
}
