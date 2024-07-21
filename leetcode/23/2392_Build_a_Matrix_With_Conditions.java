import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    List<Integer> topoSort(int n, int[][] edges) {
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
        }

        List<Integer> order = new ArrayList<>();
        int[] visited = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                boolean isValid = dfs(i, adjList, visited, order);
                if (!isValid) {
                    return new ArrayList<>();
                }
            }
        }

        Collections.reverse(order);
        return order;
    }

    boolean dfs(int u, List<List<Integer>> adjList, int[] visited, List<Integer> order) {
        visited[u] = 1;
        for (int v : adjList.get(u)) {
            if (visited[v] == 1) {
                return false;
            }

            if (visited[v] == 0) {
                boolean isValid = dfs(v, adjList, visited, order);
                if (!isValid) {
                    return false;
                }
            }
        }

        visited[u] = 2;
        order.add(u);
        return true;
    }

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        // Topological Sort, DFS, Matrix - Time: O(n + k^2), Space: O(n + k^2)
        List<Integer> rowsOrder = topoSort(k, rowConditions);
        List<Integer> colsOrder = topoSort(k, colConditions);
        if (rowsOrder.isEmpty() || colsOrder.isEmpty()) {
            return new int[0][0];
        }

        int[][] res = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rowsOrder.get(i).equals(colsOrder.get(j))) {
                    res[i][j] = rowsOrder.get(i);
                    break;
                }
            }
        }

        return res;
    }
}
