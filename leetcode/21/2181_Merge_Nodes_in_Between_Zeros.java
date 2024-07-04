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
    public ListNode mergeNodes(ListNode head) {
        // Linked List, Simulation - Time: O(n), Space: O(1)
        ListNode curr = head;
        while (curr.next != null) {
            int sum = 0;
            ListNode next = curr.next;
            while (next.val != 0) {
                sum += next.val;
                next = next.next;
            }

            next.val = sum;
            curr.next = next;
            curr = next;
        }

        return head.next;
    }
}
