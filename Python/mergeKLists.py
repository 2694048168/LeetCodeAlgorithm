#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: mergeKLists.py
@Function: 合并K个升序链表
@Link: https://leetcode-cn.com/problems/merge-k-sorted-lists/ 
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-25
"""

from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return
        n = len(lists)
        return self.merge(lists, 0, n-1)

    def merge(self, lists, left, right):
        if left == right:
            return lists[left]
        mid = left + (right - left) // 2
        l1 = self.merge(lists, left, mid)
        l2 = self.merge(lists, mid+1, right)
        return self.mergeTwoLists(l1, l2)

    def mergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2


# --------------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
