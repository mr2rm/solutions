// Definition for a binary tree node.

import java.util.ArrayList;
import java.util.List;

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
    public List<Integer> postorderTraversal(TreeNode node) {
        // Tree, DFS - Time: O(n), Space: O(n)
        List<Integer> res = new ArrayList<>();
        if (node == null) {
            return res;
        }

        List<Integer> leftNodes = postorderTraversal(node.left);
        res.addAll(leftNodes);

        List<Integer> rightNodes = postorderTraversal(node.right);
        res.addAll(rightNodes);

        res.add(node.val);
        return res;
    }
}
