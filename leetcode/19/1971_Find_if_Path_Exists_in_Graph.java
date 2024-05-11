import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    boolean dfs(int u, int destination, HashMap<Integer, ArrayList<Integer>> edgeList, HashSet<Integer> visited) {
        if (u == destination) {
            return true;
        }

        visited.add(u);
        ArrayList<Integer> neighbors = edgeList.get(u);
        if (neighbors == null) {
            return false;
        }

        for (int v : neighbors) {
            if (visited.contains(v)) {
                continue;
            }

            boolean res = dfs(v, destination, edgeList, visited);
            if (res) {
                return true;
            }
        }

        return false;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        // DFS, Connected Component - Time: O(n + e), Space: O(e)
        HashMap<Integer, ArrayList<Integer>> edgeList = new HashMap<Integer, ArrayList<Integer>>();
        for (int[] edge : edges) {
            edgeList.computeIfAbsent(edge[0], x -> new ArrayList<>()).add(edge[1]);
            edgeList.computeIfAbsent(edge[1], x -> new ArrayList<>()).add(edge[0]);
        }

        HashSet<Integer> visited = new HashSet<>();
        visited.add(source);

        return dfs(source, destination, edgeList, visited);
    }
}
