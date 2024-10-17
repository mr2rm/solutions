import java.util.PriorityQueue;

record Pair(char ch, int count) {
}

class Solution {
    public String longestDiverseString(int a, int b, int c) {
        // NOTE: Greedy, Priority Queue - Time: O(a + b + c), Space: O(1)
        StringBuilder res = new StringBuilder();
        PriorityQueue<Pair> pq = new PriorityQueue<>(
                (x, y) -> Integer.compare(y.count(), x.count()));
        if (a > 0) {
            pq.add(new Pair('a', a));
        }
        if (b > 0) {
            pq.add(new Pair('b', b));
        }
        if (c > 0) {
            pq.add(new Pair('c', c));
        }

        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            int count = top.count();

            if (res.length() >= 2
                    && res.charAt(res.length() - 1) == top.ch()
                    && res.charAt(res.length() - 2) == top.ch()) {
                if (pq.isEmpty()) {
                    break;
                }

                Pair next = pq.poll();
                res.append(next.ch());
                if (next.count() - 1 > 0) {
                    pq.add(new Pair(next.ch(), next.count() - 1));
                }
            } else {
                res.append(top.ch());
                count--;
            }

            if (count > 0) {
                pq.add(new Pair(top.ch(), count));
            }
        }

        return res.toString();
    }
}
