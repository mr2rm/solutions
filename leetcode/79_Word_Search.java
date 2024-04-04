class Solution {
    static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    boolean searchWord(char[][] board, String word, boolean[][] mark, int x, int y, int idx) {
        if (board[x][y] != word.charAt(idx)) {
            return false;
        }
        if (idx == word.length() - 1) {
            return true;
        }

        mark[x][y] = true;
        int n = board.length;
        int m = board[0].length;
        for (int i = 0; i < dir.length; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && !mark[tx][ty]) {
                boolean found = searchWord(board, word, mark, tx, ty, idx + 1);
                if (found) {
                    return true;
                }
            }
        }

        mark[x][y] = false;
        return false;
    }

    boolean solve1(char[][] board, String word) {
        // String, Backtracking - Time: O(n^4), Space: O(n^2)
        int n = board.length;
        int m = board[0].length;
        boolean[][] mark = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                boolean found = searchWord(board, word, mark, i, j, 0);
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean exist(char[][] board, String word) {
        return solve1(board, word);
    }
}