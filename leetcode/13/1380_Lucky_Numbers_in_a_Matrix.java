import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        // Array, Matrix - Time: O(n*m), Space: O(n+m)
        int n = matrix.length;
        int[] rowMin = new int[n];

        int m = matrix[0].length;
        int[] colMax = new int[m];

        for (int i = 0; i < n; i++) {
            rowMin[i] = Integer.MAX_VALUE;
            for (int j = 0; j < m; j++) {
                rowMin[i] = Math.min(rowMin[i], matrix[i][j]);
                colMax[j] = Math.max(colMax[j], matrix[i][j]);
            }
        }

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.add(matrix[i][j]);
                }
            }
        }

        return res;
    }
}
