class Solution {
    int findChar(String word, char ch) {
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                return i;
            }
        }
        return -1;
    }

    String solve2(String word, char ch) {
        // String - Time: O(n), Space: (1)
        int idx = word.indexOf(ch);
        if (idx == -1) {
            return word;
        }

        String prefix = word.substring(0, idx + 1);
        String suffix = word.substring(idx + 1);

        String reversedPrefix = new StringBuilder(prefix).reverse().toString();
        return reversedPrefix + suffix;
    }

    String solve1(String word, char ch) {
        // String, Two Pointers - Time: O(n), Space: O(1)
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
        return solve2(word, ch);
    }
}
