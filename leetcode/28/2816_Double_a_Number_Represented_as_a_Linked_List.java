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
    int getDouble(ListNode node) {
        if (node == null) {
            return 0;
        }

        int carry = getDouble(node.next);
        int res = 2 * node.val + carry;

        node.val = res % 10;
        if (res >= 10) {
            return 1;
        }
        return 0;
    }

    public ListNode doubleIt(ListNode head) {
        // Recursion, Linked List - Time: O(n), Space: O(n)
        int carry = getDouble(head);
        if (carry == 1) {
            ListNode res = new ListNode(1, head);
            return res;
        }
        return head;
    }
}
