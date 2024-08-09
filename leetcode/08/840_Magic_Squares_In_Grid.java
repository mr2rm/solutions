class Solution {
    boolean isMagicSquare(int[][] grid, int x, int y) {
        boolean[] mark = new boolean[10];
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] >= 1 && grid[i][j] <= 9 && !mark[grid[i][j]]) {
                    mark[grid[i][j]] = true;
                    continue;
                }
                return false;
            }
        }

        int dig1Sum = 0, dig2Sum = 0;
        for (int i = 0; i < 3; i++) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < 3; j++) {
                rowSum += grid[x + i][y + j];
                colSum += grid[x + j][y + i];
            }
            if (rowSum != 15 || colSum != 15) {
                return false;
            }
            dig1Sum += grid[x + i][y + i];
            dig2Sum += grid[x + i][y + 2 - i];
        }

        return dig1Sum == 15 && dig2Sum == 15;
    }

    public int numMagicSquaresInside(int[][] grid) {
        // Matrix, Array - Time: O(n * m), Space: O(1)
        int n = grid.length;
        int m = grid[0].length;

        int res = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
}
