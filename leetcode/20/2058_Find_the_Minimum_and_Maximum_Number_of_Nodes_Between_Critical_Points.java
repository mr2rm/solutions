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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        // Linked List - Time: O(n), Space: O(1)
        int minDistance = -1, maxDistance = -1;

        ListNode prev = head;
        ListNode curr = head.next;
        int firstPoint = -1, lastPoint = -1;

        int i = 1;
        while (curr != null && curr.next != null) {
            ListNode next = curr.next;

            if (curr.val < Math.min(prev.val, next.val) || curr.val > Math.max(prev.val, next.val)) {
                if (firstPoint == -1) {
                    firstPoint = lastPoint = i;
                } else {
                    if (minDistance == -1) {
                        minDistance = i - lastPoint;
                    }
                    maxDistance = i - firstPoint;
                    minDistance = Math.min(minDistance, i - lastPoint);
                    lastPoint = i;
                }
            }

            prev = curr;
            curr = next;
            i++;
        }

        return new int[] { minDistance, maxDistance };
    }
}
