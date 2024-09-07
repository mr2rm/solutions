// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

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

    boolean dfs(TreeNode treeNode, ListNode listNode) {
        if (listNode == null) {
            return true;
        }
        if (treeNode == null || treeNode.val != listNode.val) {
            return false;
        }
        return dfs(treeNode.left, listNode.next) || dfs(treeNode.right, listNode.next);
    }

    boolean checkPath(TreeNode node, ListNode head) {
        if (node == null) {
            return false;
        }

        boolean isMatched = dfs(node, head);
        if (isMatched) {
            return true;
        }

        return checkPath(node.left, head) || checkPath(node.right, head);
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        // Linked List, Tree, DFS - Time: O(n), Space: O(n)
        return checkPath(root, head);
    }
}
