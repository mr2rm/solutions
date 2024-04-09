class Solution {
    int solve1(int[] tickets, int k) {
        // Simulation - Time: O(n), Space: O(1)
        int res = 0;
        for (int i = 0; i <= k; i++) {
            res += Math.min(tickets[i], tickets[k]);
        }
        for (int i = k + 1; i < tickets.length; i++) {
            res += Math.min(tickets[i], tickets[k] - 1);
        }
        return res;
    }

    public int timeRequiredToBuy(int[] tickets, int k) {
        return solve1(tickets, k);
    }
}
