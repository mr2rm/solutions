#!/bin/python3

import math
import os
import random
import re
import sys


class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node


def print_singly_linked_list(node, sep):
    while node:
        end = sep if node.next else None
        print(node.data, end=end)
        node = node.next

# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#


def extend_list(llist, node):
    while node:
        llist.insert_node(node.data)
        node = node.next


def mergeLists(head1, head2):
    # O(n + m)
    llist = SinglyLinkedList()
    curr1, curr2 = head1, head2
    while curr1 and curr2:
        if curr1.data < curr2.data:
            curr1, data = curr1.next, curr1.data
        else:
            curr2, data = curr2.next, curr2.data
        llist.insert_node(data)

    extend_list(llist, curr1)
    extend_list(llist, curr2)
    return llist.head


if __name__ == '__main__':
    tests = int(input())
    for tests_itr in range(tests):
        llist1_count = int(input())
        llist1 = SinglyLinkedList()

        for _ in range(llist1_count):
            llist1_item = int(input())
            llist1.insert_node(llist1_item)

        llist2_count = int(input())
        llist2 = SinglyLinkedList()

        for _ in range(llist2_count):
            llist2_item = int(input())
            llist2.insert_node(llist2_item)

        llist3 = mergeLists(llist1.head, llist2.head)

        print_singly_linked_list(llist3, ' ')
