import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        // Hash Table - Time: O(n), Space: O(n)
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : target) {
            int count = map.getOrDefault(x, 0);
            map.put(x, count + 1);
        }
        for (int x : arr) {
            int count = map.getOrDefault(x, 0);
            if (count == 0) {
                return false;
            }
            map.put(x, count - 1);
        }
        return true;
    }
}
