class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        // Math, Simulation - Time: O(logn), Space: O(1)
        int res = 0;
        while (numBottles >= numExchange) {
            int exchanged = numBottles / numExchange;
            res += (exchanged * numExchange);
            numBottles = exchanged + (numBottles % numExchange);
        }

        res += numBottles;
        return res;
    }
}
