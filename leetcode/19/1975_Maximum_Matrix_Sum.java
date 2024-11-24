class Solution {
    public long maxMatrixSum(int[][] matrix) {
        // Matrix, Greedy - Time: O(n^2), Space: O(1)
        long sum = 0;
        int negativeCount = 0;
        int minAbs = Integer.MAX_VALUE;

        for (int[] row : matrix) {
            for (int x : row) {
                sum += Math.abs(x);
                minAbs = Math.min(minAbs, Math.abs(x));
                if (x < 0) {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 == 1) {
            sum -= 2 * minAbs;
        }
        return sum;
    }
}
