import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private Map<Integer, List<Integer>> edgeList;
    private int[] nodeCount;
    private int[] distances;

    void processTree(int node, int parent) {
        nodeCount[node] = 1;
        distances[node] = 0;
        for (int child : edgeList.get(node)) {
            if (child != parent) {
                processTree(child, node);
                nodeCount[node] += nodeCount[child];
                distances[node] += nodeCount[child] + distances[child];
            }
        }
    }

    void calculateDistances(int node, int parent) {
        int n = edgeList.size();
        for (int child : edgeList.get(node)) {
            if (child != parent) {
                distances[child] = distances[node] - nodeCount[child] + (n - nodeCount[child]);
                calculateDistances(child, node);
            }
        }

    }

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        // DFS, DP - Time: O(n), Space: O(n)
        nodeCount = new int[n];
        distances = new int[n];
        edgeList = new HashMap<>();

        for (int i = 0; i < n; i++) {
            edgeList.put(i, new ArrayList<>());
        }

        for (int[] edge : edges) {
            edgeList.get(edge[0]).add(edge[1]);
            edgeList.get(edge[1]).add(edge[0]);
        }

        processTree(0, -1);
        calculateDistances(0, -1);
        return distances;
    }
}
