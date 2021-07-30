#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: swapPairs.py
@Function: 两两交换链表中的节点
@Link: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-30
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        dummyHead.next = head
        temp = dummyHead
        while temp.next and temp.next.next:
            node1 = temp.next
            node2 = temp.next.next
            temp.next = node2
            node1.next = node2.next
            node2.next = node1
            temp = node1
        return dummyHead.next


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
