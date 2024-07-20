import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        // Greedy, Matrix, Priority Queue - Time: O((n+m)log(n+m)), Space: O(n+m)
        int n = rowSum.length;
        int m = colSum.length;

        Queue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < n; i++) {
            pq.add(new int[] { rowSum[i], i, 0 });
        }
        for (int j = 0; j < m; j++) {
            pq.add(new int[] { colSum[j], j, 1 });
        }

        int[][] res = new int[n][m];
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int val = top[0];
            int idx = top[1];
            boolean isRow = top[2] == 0 ? true : false;

            if (isRow) {
                if (rowSum[idx] == 0) {
                    continue;
                }

                rowSum[idx] = 0;
                for (int j = 0; j < m; j++) {
                    if (colSum[j] > 0) {
                        colSum[j] -= val;
                        res[idx][j] = val;

                        if (colSum[j] > 0) {
                            pq.add(new int[] { colSum[j], j, 1 });
                        }
                        break;
                    }
                }

            } else {
                if (colSum[idx] == 0) {
                    continue;
                }

                colSum[idx] = 0;
                for (int i = 0; i < n; i++) {
                    if (rowSum[i] > 0) {
                        rowSum[i] -= val;
                        res[i][idx] = val;

                        if (rowSum[i] > 0) {
                            pq.add(new int[] { rowSum[i], i, 0 });
                        }
                        break;
                    }
                }
            }
        }

        return res;
    }
}
