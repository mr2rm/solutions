import java.util.HashMap;
import java.util.HashSet;

class Solution {
    int solve1(int[] nums) {
        // Hash Table - Time: O(n), Space: O(n)
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (final int x : nums) {
            if (map.containsKey(x)) {
                return x;
            }
            map.put(x, true);
        }
        return -1;
    }

    int solve2(int[] nums) {
        // Ordered Set - Time: O(n), Space: O(n)
        HashSet<Integer> set = new HashSet<>();
        for (final int x : nums) {
            if (set.contains(x)) {
                return x;
            }
            set.add(x);
        }
        return -1;
    }

    public int findDuplicate(int[] nums) {
        return this.solve1(nums);
    }
}
