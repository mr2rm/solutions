import java.util.PriorityQueue;

record Pair<TFirst, TSecond>(TFirst first, TSecond second) {
}

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        // Prefix Sum, Priority Queue - Time: O(nlogn), Space: O(n)
        int shortestSubarrayLength = Integer.MAX_VALUE;
        long comulativeSum = 0;
        PriorityQueue<Pair<Long, Integer>> prefixSumHeap = new PriorityQueue<>(
                (a, b) -> Long.compare(a.first(), b.first()));

        for (int i = 0; i < nums.length; i++) {
            comulativeSum += nums[i];
            if (comulativeSum >= k) {
                shortestSubarrayLength = Math.min(shortestSubarrayLength, i + 1);
            }

            while (!prefixSumHeap.isEmpty()
                    && comulativeSum - prefixSumHeap.peek().first() >= k) {
                shortestSubarrayLength = Math.min(
                        shortestSubarrayLength, i - prefixSumHeap.poll().second());
            }

            prefixSumHeap.offer(new Pair<>(comulativeSum, i));
        }

        if (shortestSubarrayLength == Integer.MAX_VALUE) {
            return -1;
        }
        return shortestSubarrayLength;
    }
}
