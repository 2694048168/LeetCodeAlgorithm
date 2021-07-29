#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reverseList.py
@Function: 反转链表
@Link: https://leetcode-cn.com/problems/reverse-linked-list/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-29
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 迭代方式
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre


# 递归方式
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
