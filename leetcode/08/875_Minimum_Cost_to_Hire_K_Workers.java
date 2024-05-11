import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

record Worker(double wageRatio, int quality) implements Comparable<Worker> {
    @Override
    public int compareTo(Worker other) {
        if (wageRatio < other.wageRatio) {
            return -1;
        } else if (wageRatio > other.wageRatio) {
            return 1;
        }
        return 0;
    }
}

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        // Sorting, PriorityQueue, Greedy - Time: O(nlogn), Space: O(n)
        int n = wage.length;

        Worker[] workers = new Worker[n];
        for (int i = 0; i < n; i++) {
            double wageRatio = (double) wage[i] / quality[i];
            workers[i] = new Worker(wageRatio, quality[i]);
        }
        Arrays.sort(workers);

        int totalQuality = 0;
        PriorityQueue<Integer> minQualities = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < k - 1; i++) {
            minQualities.add(workers[i].quality());
            totalQuality += workers[i].quality();
        }

        double res = Double.MAX_VALUE;
        for (int i = k - 1; i < n; i++) {
            double cost = workers[i].wageRatio() * (workers[i].quality() + totalQuality);
            res = Math.min(res, cost);

            if (k > 1 && workers[i].quality() < minQualities.peek()) {
                int oldMax = minQualities.poll();
                minQualities.add(workers[i].quality());
                totalQuality = totalQuality - oldMax + workers[i].quality();
            }
        }
        return res;
    }
}
