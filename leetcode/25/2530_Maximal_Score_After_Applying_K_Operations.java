import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public long maxKelements(int[] nums, int k) {
        // Priority Queue, Greedy - Time: O(nlogn + klogn), Space: O(n)
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int x : nums) {
            pq.add(x);
        }

        long score = 0;
        while (k > 0 && !pq.isEmpty()) {
            int x = pq.poll();
            score += x;
            x = (int) Math.ceil(x / 3.);
            pq.add(x);
            k--;
        }
        return score;
    }
}
