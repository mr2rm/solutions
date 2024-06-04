import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestPalindrome(String s) {
        // Hash Table, Greedy - Time: O(n), Space: O(1)
        HashMap<Character, Integer> charCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            int count = charCount.getOrDefault(c, 0);
            charCount.put(c, count + 1);
        }

        int res = 0;
        int center = 0;
        for (Map.Entry<Character, Integer> entry : charCount.entrySet()) {
            int count = entry.getValue();
            if (count % 2 == 0) {
                res += count;
            } else {
                res += count - 1;
                center = 1;
            }
        }
        res += center;
        return res;
    }
}
