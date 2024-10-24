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
    public boolean flipEquiv(TreeNode node1, TreeNode node2) {
        // NOTE: Tree, DFS - Time: O(n), Space: O(n)
        if (node1 == null || node2 == null) {
            return node1 == null && node2 == null;
        }

        if (node1.val != node2.val) {
            return false;
        }

        boolean noSwap = flipEquiv(node1.left, node2.left)
                && flipEquiv(node1.right, node2.right);
        boolean withSwap = flipEquiv(node1.left, node2.right)
                && flipEquiv(node1.right, node2.left);
        return noSwap || withSwap;
    }
}
