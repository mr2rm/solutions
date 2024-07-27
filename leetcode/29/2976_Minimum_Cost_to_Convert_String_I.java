import java.util.Arrays;

class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        // Shortest Path, Floyd Warshall - Time: O(n^3), Space: O(n^2)
        long[][] dist = new long[26][26];
        for (long[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        for (int i = 0; i < original.length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = Math.min(dist[u][v], (long) cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long res = 0;
        for (int i = 0; i < source.length(); i++) {
            int from = source.charAt(i) - 'a';
            int to = target.charAt(i) - 'a';
            if (from == to) {
                continue;
            }

            if (dist[from][to] >= Integer.MAX_VALUE) {
                return -1;
            }
            res += dist[from][to];
        }
        return res;
    }
}
