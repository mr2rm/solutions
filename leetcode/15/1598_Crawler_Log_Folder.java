class Solution {
    public int minOperations(String[] logs) {
        // Simulation, Stack - Time: O(n), Space: O(1)
        int res = 0;
        for (String operation : logs) {
            switch (operation) {
                case "../":
                    res = Math.max(res - 1, 0);
                    break;
                case "./":
                    break;
                default:
                    res++;
            }
        }
        return res;
    }
}
