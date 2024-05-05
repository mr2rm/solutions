// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public void deleteNode(ListNode node) {
        // Linked List, Two Pointers - Time: O(n), Space: O(1)
        ListNode prev = node;
        ListNode curr = node;

        while (curr != null) {
            if (curr.next != null) {
                curr.val = curr.next.val;
            } else {
                prev.next = null;
            }
            prev = curr;
            curr = curr.next;
        }
    }
}
