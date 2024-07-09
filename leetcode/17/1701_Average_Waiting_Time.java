class Solution {
    public double averageWaitingTime(int[][] customers) {
        // Simulation - Time: O(n), Space: O(1)
        int currentTime = 0;
        long totalWaitingTime = 0;

        for (int[] customer : customers) {
            int arrival = customer[0];
            int time = customer[1];

            if (arrival < currentTime) {
                totalWaitingTime += currentTime - arrival;
            } else {
                currentTime = arrival;
            }

            totalWaitingTime += time;
            currentTime += time;
        }

        double res = (double) totalWaitingTime / customers.length;
        return res;
    }
}
