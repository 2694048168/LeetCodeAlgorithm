#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getIntersectionNode.py
@Function: 相交链表
@Link: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
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
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        return A


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
