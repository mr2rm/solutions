import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> commonChars(String[] words) {
        // Hash Table - Time: O(n*m), Space: O(1)
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : words[0].toCharArray()) {
            int count = map.getOrDefault(c, 0);
            map.put(c, count + 1);
        }

        for (int i = 1; i < words.length; i++) {
            HashMap<Character, Integer> temp = new HashMap<>();
            for (char c : words[i].toCharArray()) {
                int count = temp.getOrDefault(c, 0);
                if (count < map.getOrDefault(c, 0)) {
                    temp.put(c, count + 1);
                }
            }
            map = temp;
        }

        List<String> res = new ArrayList<String>();
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            String s = Character.toString(entry.getKey());
            for (int i = 0; i < entry.getValue(); i++) {
                res.add(s);
            }
        }
        return res;
    }
}
