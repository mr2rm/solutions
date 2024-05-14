import java.util.Arrays;

class Solution {
    public int matrixScore(int[][] grid) {
        // Greedy, Bit Manipulation, Array - Time: O(n^2), Space: O(n)
        int n = grid.length;
        int m = grid[0].length;
        int[] rowScore = new int[n];
        int[] colSum = new int[m];

        for (int i = 0; i < n; i++) {
            int flipper = grid[i][0] == 0 ? 1 : 0;
            for (int j = 0; j < m; j++) {
                int x = grid[i][j] ^ flipper;
                rowScore[i] <<= 1;
                rowScore[i] += x;
                colSum[j] += x;
            }
        }

        for (int j = 1; j < m; j++) {
            if (n - colSum[j] <= colSum[j])
                continue;

            int mask = 1 << (m - j - 1);
            for (int i = 0; i < n; i++) {
                rowScore[i] ^= mask;
            }
        }

        int res = Arrays.stream(rowScore).sum();
        return res;
    }
}
