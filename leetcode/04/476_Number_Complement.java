class Solution {
    public int findComplement(int num) {
        // Bit Manipulation - Time: O(1), Space: O(1)
        int n = Integer.toBinaryString(num).length();
        int allOne = (1 << n) - 1;
        return num ^ allOne;
    }
}
