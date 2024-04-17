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
    void addRow(TreeNode node, int level, int val, int depth) {
        if (node == null) {
            return;
        }

        if (level == depth - 1) {
            node.left = new TreeNode(val, node.left, null);
            node.right = new TreeNode(val, null, node.right);
            return;
        }

        addRow(node.left, level + 1, val, depth);
        addRow(node.right, level + 1, val, depth);
    }

    TreeNode solve1(TreeNode root, int val, int depth) {
        // Tree, DFS - Time: O(n), Space: O(n)
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val, root, null);
            return newRoot;
        }
        addRow(root, 1, val, depth);
        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        return solve1(root, val, depth);
    }
}
