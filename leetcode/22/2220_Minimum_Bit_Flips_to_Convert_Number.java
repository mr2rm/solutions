class Solution {
    public int minBitFlips(int start, int goal) {
        // Bit Manipulation - Time: O(1), Space: O(1)
        int res = 0;
        String diff = Integer.toBinaryString(start ^ goal);
        for (char c : diff.toCharArray()) {
            if (c == '1') {
                res++;
            }
        }
        return res;
    }
}
