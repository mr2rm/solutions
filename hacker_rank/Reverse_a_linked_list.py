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

#
# Complete the 'reverse' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#


def reverse_node(prev, node):
    head = node
    if node.next:
        head = reverse_node(node, node.next)
    node.next = prev
    return head


def reverse(llist):
    # O(n)
    # return reverse_node(None, llist)

    # O(n)
    prev, curr = None, llist
    while curr:
        _next = curr.next
        curr.next = prev
        prev, curr = curr, _next
    return prev


if __name__ == '__main__':
    tests = int(input())
    for tests_itr in range(tests):
        llist_count = int(input())
        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist.head)
        print_singly_linked_list(llist1, ' ')
