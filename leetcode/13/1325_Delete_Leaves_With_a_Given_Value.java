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
    boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }

    void dfs(TreeNode node, int target) {
        if (node == null) {
            return;
        }

        if (node.left != null) {
            dfs(node.left, target);
            if (node.left.val == target && isLeaf(node.left)) {
                node.left = null;
            }
        }

        if (node.right != null) {
            dfs(node.right, target);
            if (node.right.val == target && isLeaf(node.right)) {
                node.right = null;
            }
        }
    }

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        // DFS, Tree - Time: O(n), Space: O(logn)
        dfs(root, target);
        if (root.val == target && isLeaf(root)) {
            return null;
        }
        return root;
    }
}
