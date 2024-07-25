import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    int[] heapSort(int[] nums) {
        // Priority Queue - Time: (nlogn), Space: O(n)
        Queue<Integer> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.add(x);
        }

        List<Integer> arr = new ArrayList<>();
        while (!pq.isEmpty()) {
            int x = pq.poll();
            arr.add(x);
        }

        int[] res = arr.stream().mapToInt(i -> i).toArray();
        return res;
    }

    public int[] sortArray(int[] nums) {
        return heapSort(nums);
    }
}
