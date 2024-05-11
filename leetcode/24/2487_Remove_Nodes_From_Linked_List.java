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

class Solution {
    ListNode getNonIncreasing(ListNode node) {
        // Linked List, Recursion - Time: O(n), Space: O(n)
        if (node.next == null) {
            return node;
        }

        ListNode head = getNonIncreasing(node.next);
        if (node.val < head.val) {
            return head;
        }

        node.next = head;
        return node;
    }

    public ListNode removeNodes(ListNode head) {
        return getNonIncreasing(head);
    }
}
