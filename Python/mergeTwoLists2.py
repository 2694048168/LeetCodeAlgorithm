#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: mergeTwoLists2.py
@Function: 合并两个排序的链表
@Link: https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-13
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = dum = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next, l1 = l1, l1.next
            else:
                cur.next, l2 = l2, l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return dum.next


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
