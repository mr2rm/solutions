class Solution {
    int solve1(int start, int goal) {
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

    int solve2(int start, int goal) {
        // Bit Manipulation - Time: O(1), Space: O(1)
        int res = 0;
        int diff = start ^ goal;
        while (diff > 0) {
            diff &= (diff - 1);
            res++;
        }
        return res;
    }

    public int minBitFlips(int start, int goal) {
        return solve2(start, goal);
    }
}
