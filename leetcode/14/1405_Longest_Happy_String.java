import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public String longestDiverseString(int a, int b, int c) {
        // NOTE: Greedy, Priority Queue - Time: O(n), Space: O(n)
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> Integer.compare(y[1], x[1]));
        if (a > 0) {
            pq.add(new int[] { 'a', a });
        }
        if (b > 0) {
            pq.add(new int[] { 'b', b });
        }
        if (c > 0) {
            pq.add(new int[] { 'c', c });
        }

        StringBuilder sb = new StringBuilder();
        int lastChar = 0, lastCharCount = 0;
        while (!pq.isEmpty()) {
            Queue<int[]> tmp = new LinkedList<>();
            boolean found = false;
            int[] next = null;
            while (!pq.isEmpty()) {
                next = pq.poll();
                if (next[0] != lastChar || lastCharCount < 2) {
                    found = true;
                    break;
                }
                tmp.add(next);
            }

            if (!found) {
                break;
            }

            if (next[0] != lastChar) {
                lastCharCount = 0;
            }
            lastChar = next[0];
            lastCharCount++;
            sb.append((char) lastChar);

            if (next[1] - 1 > 0) {
                tmp.add(new int[] { next[0], next[1] - 1 });
            }
            while (!tmp.isEmpty()) {
                int[] x = tmp.poll();
                pq.add(x);
            }
        }

        return sb.toString();
    }
}
