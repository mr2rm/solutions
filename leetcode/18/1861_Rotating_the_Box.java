class Solution {
    public char[][] rotateTheBox(char[][] box) {
        // Matrix, Simulation - Time: O(n^3), Space: O(n^2)
        int n = box.length;
        int m = box[0].length;

        char[][] rotatedBox = new char[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotatedBox[j][n - i - 1] = box[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = m - 2; i >= 0; i--) {
                if (rotatedBox[i][j] == '#') {
                    int k = i + 1;
                    while (k < m && rotatedBox[k][j] == '.') {
                        k++;
                    }
                    if (rotatedBox[k - 1][j] == '.') {
                        rotatedBox[k - 1][j] = '#';
                        rotatedBox[i][j] = '.';
                    }
                }
            }
        }

        return rotatedBox;
    }
}
