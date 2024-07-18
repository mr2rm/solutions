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
    int[] dfs(TreeNode node, int distance) {
        int[] res = new int[12];

        if (node == null) {
            return res;
        }

        if (node.left == null && node.right == null) {
            res[0] = 1;
            return res;
        }

        int[] leftRes = dfs(node.left, distance);
        int[] rightRes = dfs(node.right, distance);

        for (int i = 1; i <= 10; i++) {
            res[i] = leftRes[i - 1] + rightRes[i - 1];
        }

        res[11] = leftRes[11] + rightRes[11];
        for (int l = 0; l <= distance; l++) {
            for (int r = 0; r <= distance; r++) {
                if (l + r + 2 <= distance) {
                    res[11] += leftRes[l] * rightRes[r];
                }
            }
        }

        return res;
    }

    public int countPairs(TreeNode root, int distance) {
        // DFS, Tree - Time: O(n * d^2), Space: O(h)
        int[] res = dfs(root, distance);
        return res[11];
    }
}
