#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: detectCycle.py
@Function: 环形链表 II 双指针策略
@Link: https://leetcode-cn.com/problems/linked-list-cycle-ii/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-07
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# https://en.wikipedia.org/wiki/Cycle_detection
# 快慢指针算法
class Solution:
    def detectCycle(self, head):
        """给定一个链表，如果有环路，找出环路的开始点.

        Args:
            head (ListNode): 表示环路的链表。
        """
        slow, fast = head, head
        # 判断是否存在环路
        while True:
            if not (fast and fast.next):
                return
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                break

        # 如果存在，查找环路节点
        fast = head
        while(fast != slow):
            slow = slow.next
            fast = fast.next
        return fast


# --------------------------
if __name__ == "__main__":
    pass