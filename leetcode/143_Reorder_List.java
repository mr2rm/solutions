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

    ListNode getMiddle(ListNode head) {
        // Slow-Fast, Iterative - Time: O(n), Space: O(1)
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    void solve(ListNode head) {
        // Iterative - Time: O(n), Space: O(1)
        ListNode middle = this.getMiddle(head);
        ListNode tail = this.reverse(middle);
        while (tail.next != null) {
            ListNode nextHead = head.next;
            ListNode nextTail = tail.next;
            head.next = tail;
            tail.next = nextHead;
            head = nextHead;
            tail = nextTail;
        }
    }

    public void reorderList(ListNode head) {
        this.solve(head);
    }
}
