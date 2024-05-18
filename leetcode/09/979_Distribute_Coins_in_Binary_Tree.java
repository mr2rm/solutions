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
    int move(TreeNode parent, TreeNode child) {
        if (child == null) {
            return 0;
        }

        int ret = Math.abs(child.val - 1);
        parent.val += child.val - 1;
        child.val = 1;
        return ret;
    }

    int distribute(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int res = 0;
        res += distribute(node.left) + move(node, node.left);
        res += distribute(node.right) + move(node, node.right);

        return res;
    }

    public int distributeCoins(TreeNode root) {
        // Tree, DFS - Time: O(n), Space: O(logn)
        return distribute(root);
    }
}
