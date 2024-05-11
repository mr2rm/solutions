import java.util.HashMap;

class Solution {
    boolean solve1(String s, String t) {
        // String, Hash Table - Time: O(n), Space: O(n)
        HashMap<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if (map.containsKey(c1)) {
                if (map.get(c1) != c2) {
                    return false;
                }
                continue;
            } else if (map.containsValue(c2)) {
                return false;
            }
            map.put(c1, c2);
        }
        return true;
    }

    public boolean isIsomorphic(String s, String t) {
        return solve1(s, t);        
    }
}