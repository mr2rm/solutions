// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    void solve1(ListNode node) {
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

    void solve2(ListNode node) {
        // Linked List - Time: O(1), Space: O(1)
        node.val = node.next.val;
        node.next = node.next.next;
    }

    public void deleteNode(ListNode node) {
        solve2(node);
    }
}
