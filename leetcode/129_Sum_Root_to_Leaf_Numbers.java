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
    int calculateSum(TreeNode node, int num) {
        // null
        if (node == null) {
            return 0;
        }

        int newNum = 10 * num + node.val;

        // leaf node
        if (node.left == null && node.right == null) {
            return newNum;
        }

        return calculateSum(node.left, newNum) + calculateSum(node.right, newNum);
    }

    int solve1(TreeNode root) {
        // Tree, DFS - Time: O(n), Space: O(n)
        return calculateSum(root, 0);
    }

    public int sumNumbers(TreeNode root) {
        return solve1(root);
    }
}
