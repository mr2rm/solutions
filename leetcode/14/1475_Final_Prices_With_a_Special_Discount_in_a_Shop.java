class Solution {
    /**
     * Brute Force: Time: O(n^2), Space: O(n)
     * 
     * @param prices prices of items in the shop
     * @return
     */
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return answer;
    }
}
