# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def get_val(self, node):
        if not node:
            return 0, None
        return node.val, node.next

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Time: O(n), Space O(n)
        res = curr = None
        c = 0
        while l1 or l2:
            a, l1 = self.get_val(l1)
            b, l2 = self.get_val(l2)
            c, t = divmod(a + b + c, 10)
            node = ListNode(t)
            if curr:
                curr.next = node
            curr = node
            if not res:
                res = node
        if c:
            curr.next = ListNode(c)
        return res
