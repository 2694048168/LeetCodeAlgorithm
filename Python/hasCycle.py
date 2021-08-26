#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: hasCycle.py
@Function: 环形链表
@Link: https://leetcode-cn.com/problems/linked-list-cycle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-26
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False

        slow = head
        fast = head.next

        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next

        return True


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
