import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public long pickGifts(int[] gifts, int k) {
        // NOTE: Simulation, Priority Queue - Time: O(nlogn), Space: O(n)
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        pq.addAll(IntStream.of(gifts).boxed().collect(Collectors.toList()));

        while (k > 0) {
            int top = pq.poll();
            int sqrt = (int) Math.sqrt(top);
            pq.add(sqrt);
            k--;
        }

        long res = 0;
        while (!pq.isEmpty()) {
            res += pq.poll();
        }
        return res;
    }
}
