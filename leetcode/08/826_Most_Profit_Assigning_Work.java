class Solution {
    int solve1(int[] difficulty, int[] profit, int[] worker) {
        // Greedy, Complete Search - Time: O(n*m), Space: O(1)
        int res = 0;
        for (int maxDifficulty : worker) {
            int maxProfit = 0;
            for (int i = 0; i < difficulty.length; i++) {
                if (difficulty[i] <= maxDifficulty) {
                    maxProfit = Math.max(maxProfit, profit[i]);
                }
            }
            res += maxProfit;
        }
        return res;
    }

    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        return solve1(difficulty, profit, worker);
    }
}
