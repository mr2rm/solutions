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
    ListNode solution1(ListNode list1, int a, int b, ListNode list2) {
        // Linked List - Time: O(n), Space: O(1)
        ListNode list2End = list2;
        while (list2End.next != null) {
            list2End = list2End.next;
        }

        ListNode current = list1;
        for (int i = 0; current != null; i++) {
            ListNode next = current.next;
            if (i == a - 1) {
                current.next = list2;
            } else if (i == b + 1) {
                list2End.next = current;
            }
            current = next;
        }

        return list1;
    }

    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        return this.solution1(list1, a, b, list2);
    }
}
