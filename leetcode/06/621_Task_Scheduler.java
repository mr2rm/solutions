import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    int solution1(char[] tasks, int n) {
        // Greedy, Hash Table, Priority Queue - Time: O(tlogt), Space: O(t)
        HashMap<Character, Integer> frequency = new HashMap<>();
        for (char t : tasks) {
            frequency.put(t, frequency.getOrDefault(t, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int value : frequency.values()) {
            pq.add(value);
        }

        int res = 0;
        while (!pq.isEmpty()) {
            int fleet = n + 1;
            ArrayList<Integer> nextRound = new ArrayList<>();

            while (!pq.isEmpty() && fleet > 0) {
                int topFrequency = pq.poll();
                topFrequency--;
                if (topFrequency > 0) {
                    nextRound.add(topFrequency);
                }
                fleet--;
                res++;
            }

            for (int freq : nextRound) {
                pq.add(freq);
            }
            if (!pq.isEmpty()) {
                res += fleet;
            }
        }
        return res;
    }

    public int leastInterval(char[] tasks, int n) {
        return this.solution1(tasks, n);
    }
}
