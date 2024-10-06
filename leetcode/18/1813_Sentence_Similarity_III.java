class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        // Two Pointers, String - Time: O(n + m), Space: O(n + m)
        if (sentence1.length() > sentence2.length()) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        String[] words1 = sentence1.split(" ");
        int words1Length = words1.length;
        String[] words2 = sentence2.split(" ");
        int words2Length = words2.length;

        int start = 0;
        while (start < words1Length && words1[start].equals(words2[start])) {
            start++;
        }

        int end1 = words1Length - 1, end2 = words2Length - 1;
        while (end1 >= 0 && words1[end1].equals(words2[end2])) {
            end1--;
            end2--;
        }

        return start > end1;
    }
}
