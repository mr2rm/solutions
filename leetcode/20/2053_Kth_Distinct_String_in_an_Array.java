import java.util.HashMap;
import java.util.Map;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        // Hash Table - Time: O(n), Space: O(n)
        Map<String, Integer> map = new HashMap<>();
        for (String s : arr) {
            int count = map.getOrDefault(s, 0);
            map.put(s, count + 1);
        }

        for (String s : arr) {
            int count = map.getOrDefault(s, 0);
            if (count == 1) {
                k--;
            }

            if (k == 0) {
                return s;
            }
        }

        return "";
    }
}
