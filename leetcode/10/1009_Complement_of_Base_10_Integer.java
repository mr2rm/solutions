class Solution {
    public int bitwiseComplement(int n) {
        // Bit Manipulation - Time: O(1), Space: O(1)
        int len = Integer.toBinaryString(n).length();
        int allOne = (1 << len) - 1;
        return n ^ allOne;
    }
}
