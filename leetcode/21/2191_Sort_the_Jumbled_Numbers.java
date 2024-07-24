import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

record Pair(int mappedValue, int index) implements Comparable<Pair> {

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(mappedValue, other.mappedValue);
    }

}

class Solution {
    int mapNumber(int n, int[] mapping) {
        int res = 0;
        String digits = Integer.toString(n);
        for (int i = 0; i < digits.length(); i++) {
            int d = digits.charAt(i) - '0';
            res *= 10;
            res += mapping[d];
        }
        return res;
    }

    public int[] sortJumbled(int[] mapping, int[] nums) {
        // Array, Sorting - Time: O(nlogn), Space: O(n)
        int n = nums.length;

        List<Pair> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int mappedValue = mapNumber(nums[i], mapping);
            arr.add(new Pair(mappedValue, i));
        }

        Collections.sort(arr);

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int j = arr.get(i).index();
            res[i] = nums[j];
        }

        return res;
    }
}
