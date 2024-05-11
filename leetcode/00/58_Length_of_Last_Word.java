class Solution {
    int solve2(String s) {
        int i, j;
        for (j = s.length() - 1; j >= 0 && s.charAt(j) == ' '; j--);
        for (i = j; i >= 0 && s.charAt(i) != ' '; i--);
        String lastWord = s.substring(i + 1, j + 1);
        return lastWord.length();
    }

    int solve1(String s) {
        String[] words = s.split(" ");
        String lastWord = words[words.length - 1];
        return lastWord.length();
    }

    public int lengthOfLastWord(String s) {
        return solve2(s);
    }
}