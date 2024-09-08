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
    int countList(ListNode node) {
        int count = 0;
        while (node != null) {
            count++;
            node = node.next;
        }

        return count;
    }

    ListNode splitList(ListNode node, int size) {
        ListNode prev = null;
        for (int i = 0; i < size; i++) {
            prev = node;
            node = node.next;
        }

        prev.next = null;
        return node;
    }

    public ListNode[] splitListToParts(ListNode head, int k) {
        // Linked List - Time: O(n), Space: O(n)
        int count = countList(head);
        int q = count / k, r = count % k;

        ListNode node = head;
        ListNode[] res = new ListNode[k];
        for (int i = 0; node != null; i++) {
            res[i] = node;
            int size = q + (i < r ? 1 : 0);
            node = splitList(node, size);
        }

        return res;
    }
}
