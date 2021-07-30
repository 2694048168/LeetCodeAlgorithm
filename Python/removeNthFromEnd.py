#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: removeNthFromEnd.py
@Function: 删除链表的倒数第 N 个结点
@Link: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        first = head
        second = dummy
        for i in range(n):
            first = first.next

        while first:
            first = first.next
            second = second.next
        
        second.next = second.next.next
        return dummy.next


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
