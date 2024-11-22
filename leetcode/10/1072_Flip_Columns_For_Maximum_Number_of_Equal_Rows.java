import java.util.Arrays;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // Brute Force, Matrix - Time: O(m^2 * n), Space: O(n)
        int n = matrix[0].length;
        int res = 0;

        for (int[] currentRow : matrix) {
            int[] flippedRow = new int[n];
            for (int i = 0; i < n; i++) {
                flippedRow[i] = 1 - currentRow[i];
            }

            int equalRows = 0;
            for (int[] row : matrix) {
                if (Arrays.equals(row, currentRow) || Arrays.equals(row, flippedRow)) {
                    equalRows++;
                }
            }
            res = Math.max(res, equalRows);
        }

        return res;
    }
}
