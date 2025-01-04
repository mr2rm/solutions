import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countPalindromicSubsequence(String s) {
        // Greedy, Set, Hash Table - Time: O(n), Space: O(1)
        Set<Character> letters = new HashSet<>();
        for (char c : s.toCharArray()) {
            letters.add(c);
        }

        int n = s.length();
        int result = 0;
        for (char c : letters) {
            int l = 0;
            while (s.charAt(l) != c) {
                l++;
            }

            int r = n - 1;
            while (s.charAt(r) != c) {
                r--;
            }

            Set<Character> uniqueLetters = new HashSet<>();
            for (int i = l + 1; i < r; i++) {
                uniqueLetters.add(s.charAt(i));
            }
            result += uniqueLetters.size();
        }

        return result;
    }
}
