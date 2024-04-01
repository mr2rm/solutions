class Solution {
    int solve1(String s) {
        String[] words = s.split(" ");
        String lastWord = words[words.length - 1];
        return lastWord.length();
    }

    public int lengthOfLastWord(String s) {
        return solve1(s);
    }
}