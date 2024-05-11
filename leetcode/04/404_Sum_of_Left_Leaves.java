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
    int getLeftSum(TreeNode node) {
        int sum = 0;

        if (node.left != null) {
            TreeNode leftNode = node.left;
            if (leftNode.left != null || leftNode.right != null) {
                sum += getLeftSum(leftNode);
            } else {
                sum += leftNode.val;
            }
        }

        if (node.right != null) {
            sum += getLeftSum(node.right);
        }

        return sum;
    }

    int solve1(TreeNode root) {
        // Tree, DFS - Time: O(n), Space: O(n)
        return getLeftSum(root);
    }

    public int sumOfLeftLeaves(TreeNode root) {
        return solve1(root);
    }
}
