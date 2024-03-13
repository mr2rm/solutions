from typing import Optional

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def count_subtree_nodes(self, node: TreeNode) -> int:
        # Recursive - Time: O(n), Space: O(n)
        if node is None:
            return 0
        node.cnt = self.count_subtree_nodes(
            node.left) + self.count_subtree_nodes(node.right) + 1
        return node.cnt

    @staticmethod
    def get_node_index(node: TreeNode, start_index) -> int:
        res = start_index
        if node.left:
            res += node.left.cnt
        return res

    def find(self, node: TreeNode, start_index: int, target_index: int) -> int:
        # Recursive - Time: O(n), Space: O(n)
        index = self.get_node_index(node, start_index)
        if index == target_index:
            return node.val
        if target_index < index:
            return self.find(node.left, start_index, target_index)
        return self.find(node.right, index + 1, target_index)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # Recursive - Time: O(n), Space: O(n)
        self.count_subtree_nodes(root)
        return self.find(root, 1, k)
