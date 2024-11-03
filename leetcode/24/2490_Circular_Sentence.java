class Solution {
    public boolean checkWords(String previous, String current) {
        int lastIndex = previous.length() - 1;
        return previous.charAt(lastIndex) == current.charAt(0);
    }

    public boolean isCircularSentence(String sentence) {
        // String - Time: O(n), Space: O(n)
        String[] words = sentence.split(" ");
        int n = words.length;

        for (int i = 1; i < n; i++) {
            if (!checkWords(words[i - 1], words[i])) {
                return false;
            }
        }
        return checkWords(words[n - 1], words[0]);
    }
}
