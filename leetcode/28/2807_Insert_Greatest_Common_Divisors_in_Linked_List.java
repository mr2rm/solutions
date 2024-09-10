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
    int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        // Linked List, Math - Time: O(n * log(min(a, b))), Space: O(1)
        ListNode prev = head, curr = head.next;
        while (curr != null) {
            int val = gcd(prev.val, curr.val);
            prev.next = new ListNode(val, curr);
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}
