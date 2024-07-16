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
    String dfs(TreeNode node, StringBuilder dir, int target) {
        if (node == null) {
            return "";
        }

        if (node.val == target) {
            return dir.toString();
        }

        dir.append('L');
        String leftResult = dfs(node.left, dir, target);
        dir.setLength(dir.length() - 1);
        if (!leftResult.isEmpty()) {
            return leftResult;
        }

        dir.append('R');
        String rightResult = dfs(node.right, dir, target);
        dir.setLength(dir.length() - 1);
        if (!rightResult.isEmpty()) {
            return rightResult;
        }

        return "";
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        // DFS, Tree, String - Time: O(n), Space: O(logn)
        String startDir = dfs(root, new StringBuilder(), startValue);
        String destDir = dfs(root, new StringBuilder(), destValue);

        int i = 0;
        while (i < startDir.length() && i < destDir.length() &&
                startDir.charAt(i) == destDir.charAt(i)) {
            i++;
        }

        StringBuilder res = new StringBuilder();
        for (int j = i; j < startDir.length(); j++) {
            res.append('U');
        }
        for (int j = i; j < destDir.length(); j++) {
            res.append(destDir.charAt(j));
        }

        return res.toString();
    }
}
