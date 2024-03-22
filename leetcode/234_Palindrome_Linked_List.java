/* Definition for singly-linked list. */
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
    ListNode getMiddle(ListNode head) {
        // Slow & Fast - Time: O(n), Space: O(1)
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return fast == null ? slow : slow.next;
    }

    ListNode reverse(ListNode head) {
        // Iterative - Time: O(n), Space: O(1)
        ListNode previous = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = previous;
            previous = head;
            head = next;
        }
        return previous;
    }

    boolean isEqual(ListNode a, ListNode b) {
        // Palindrome, Iterative - Time: O(n), Space: O(1)
        while (a != null && b != null) {
            if (a.val != b.val)
                return false;
            a = a.next;
            b = b.next;
        }
        return true;
    }

    boolean solution1(ListNode head) {
        // Linked List, Palindrome, Iterative, Two Pointers - Time: O(n), Space: O(1)
        ListNode middle = this.getMiddle(head);
        ListNode reverseHead = this.reverse(middle);
        return this.isEqual(head, reverseHead);
    }

    public boolean isPalindrome(ListNode head) {
        return this.solution1(head);
    }
}
