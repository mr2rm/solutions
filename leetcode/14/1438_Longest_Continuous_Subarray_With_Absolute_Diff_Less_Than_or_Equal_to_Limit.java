import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        // Heap, Sliding Window - Time: O(nlogn), Space: O(n)
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        int l = 0, res = 0;
        for (int r = 0; r < nums.length; r++) {
            minHeap.offer(new int[] { nums[r], r });
            maxHeap.offer(new int[] { nums[r], r });

            while (maxHeap.peek()[0] - minHeap.peek()[0] > limit) {
                l = Math.min(minHeap.peek()[1], maxHeap.peek()[1]) + 1;
                while (minHeap.peek()[1] < l) {
                    minHeap.poll();
                }
                while (maxHeap.peek()[1] < l) {
                    maxHeap.poll();
                }
            }

            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}
