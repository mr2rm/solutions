#!/bin/python3

import math
import os
import random
import re
import sys


class DoublyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = DoublyLinkedListNode(node_data)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node
            node.prev = self.tail
        self.tail = node


def print_doubly_linked_list(node, sep):
    while node:
        end = sep if node.next else None
        print(node.data, end=end)
        node = node.next

#
# Complete the 'reverse' function below.
#
# The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
# The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
#

#
# For your reference:
#
# DoublyLinkedListNode:
#     int data
#     DoublyLinkedListNode next
#     DoublyLinkedListNode prev
#
#


def reverse_node(prev, node):
    head = node
    if node.next:
        head = reverse_node(node, node.next)
    node.next, node.prev = prev, node.next
    return head


def reverse(llist):
    # O(n)
    # return reverse_node(None, llist)

    # O(n)
    prev, curr = None, llist
    while curr:
        _next = curr.next
        curr.prev, curr.next = _next, prev
        prev, curr = curr, _next
    return prev


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        llist_count = int(input())
        llist = DoublyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist.head)
        print_doubly_linked_list(llist1, ' ')
