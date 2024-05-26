import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    static List<String> res;

    void findSentences(int i, StringBuilder sentence, String s, HashSet<String> wordSet) {
        if (i == s.length()) {
            res.add(sentence.toString());
        }

        if (i > 0) {
            sentence.append(" ");
        }

        StringBuilder word = new StringBuilder();
        for (int j = i; j < s.length(); j++) {
            word.append(s.charAt(j));
            if (wordSet.contains(word.toString())) {
                sentence.append(word);
                findSentences(j + 1, sentence, s, wordSet);
                sentence.delete(sentence.length() - word.length(), sentence.length());
            }
        }

        if (i > 0) {
            sentence.deleteCharAt(sentence.length() - 1);
        }
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Backtracking - Time: O(2^n), Space: O(2^n)
        res = new ArrayList<>();
        HashSet<String> wordSet = new HashSet<>(wordDict);
        StringBuilder sentence = new StringBuilder();
        findSentences(0, sentence, s, wordSet);
        return res;
    }
}
