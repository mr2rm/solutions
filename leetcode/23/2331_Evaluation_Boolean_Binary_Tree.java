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
    boolean evaluate(TreeNode node) {
        if (node.left == null && node.right == null) {
            return node.val == 1;
        }

        boolean left = evaluate(node.left);
        boolean right = evaluate(node.right);

        if (node.val == 2) {
            return left || right;
        }
        return left && right;
    }

    public boolean evaluateTree(TreeNode root) {
        // Tree, DFS - Time: O(n), Space: O(logn)
        return evaluate(root);
    }
}
