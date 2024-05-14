import java.util.Arrays;

class Solution {
    public int matrixScore(int[][] grid) {
        // Greedy, Bit Manipulation, Array - Time: O(n^2), Space: O(n)
        int n = grid.length;
        int m = grid[0].length;

        int[] rowScore = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowScore[i] <<= 1;
                rowScore[i] += grid[i][j];
            }
            if (grid[i][0] == 0) {
                rowScore[i] ^= (1 << m) - 1;
            }
        }

        for (int j = 1; j < m; j++) {
            int mask = 1 << (m - j - 1);

            int colSum = 0;
            for (int score : rowScore) {
                if ((score & mask) != 0) {
                    colSum += 1;
                }
            }

            if (n - colSum <= colSum)
                continue;

            for (int i = 0; i < n; i++) {
                rowScore[i] ^= mask;
            }
        }

        int res = Arrays.stream(rowScore).sum();
        return res;
    }
}
