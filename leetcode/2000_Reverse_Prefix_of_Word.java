class Solution {
    int findChar(String word, char ch) {
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                return i;
            }
        }
        return -1;
    }

    String solve1(String word, char ch) {
        // String, 2 Pointers - Time: O(n), Space: O(1)
        int idx = findChar(word, ch);
        if (idx == -1) {
            return word;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = idx; i >= 0; i--) {
            sb.append(word.charAt(i));
        }
        for (int i = idx + 1; i < word.length(); i++) {
            sb.append(word.charAt(i));
        }

        return sb.toString();
    }

    public String reversePrefix(String word, char ch) {
        return solve1(word, ch);
    }
}
