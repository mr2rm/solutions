import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        // Hash Table, Tree - Time: O(n), Space: O(n)
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        Set<Integer> parents = new HashSet<>();

        for (int[] edge : descriptions) {
            if (!nodeMap.containsKey(edge[0])) {
                nodeMap.put(edge[0], new TreeNode(edge[0]));
                parents.add(edge[0]);
            }

            if (!nodeMap.containsKey(edge[1])) {
                nodeMap.put(edge[1], new TreeNode(edge[1]));
            } else if (parents.contains(edge[1])) {
                parents.remove(edge[1]);
            }

            TreeNode parent = nodeMap.get(edge[0]);
            TreeNode child = nodeMap.get(edge[1]);
            if (edge[2] == 1) {
                parent.left = child;
            } else {
                parent.right = child;
            }
        }

        TreeNode root = nodeMap.get(parents.iterator().next());
        return root;
    }
}
