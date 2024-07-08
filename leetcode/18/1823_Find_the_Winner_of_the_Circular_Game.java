import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int findTheWinner(int n, int k) {
        // Simulation, Queue - Time: O(n*k), Space: O(n)
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }

        while (queue.size() > 1) {
            for (int i = 1; i < k; i++) {
                int head = queue.poll();
                queue.add(head);
            }
            queue.poll();
        }

        return queue.peek();
    }
}
