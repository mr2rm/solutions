
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
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
    TreeNode dfs(TreeNode node, Set<Integer> deleteSet, List<TreeNode> forest) {
        if (node == null) {
            return null;
        }

        node.left = dfs(node.left, deleteSet, forest);
        node.right = dfs(node.right, deleteSet, forest);

        if (deleteSet.contains(node.val)) {
            if (node.left != null) {
                forest.add(node.left);
            }
            if (node.right != null) {
                forest.add(node.right);
            }
            return null;
        }

        return node;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        // Hash Table, DFS, Tree - Time: O(n), Space: O(nlogn)
        Set<Integer> deleteSet = new HashSet<>();
        for (int x : to_delete) {
            deleteSet.add(x);
        }

        List<TreeNode> forest = new ArrayList<TreeNode>();
        root = dfs(root, deleteSet, forest);
        if (root != null) {
            forest.add(root);
        }

        return forest;
    }
}
