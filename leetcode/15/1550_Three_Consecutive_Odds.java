class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int oddCount = 0;
        for (int x : arr) {
            if (x % 2 != 0) {
                oddCount++;
            } else {
                oddCount = 0;
            }

            if (oddCount == 3) {
                return true;
            }
        }
        return false;
    }
}
