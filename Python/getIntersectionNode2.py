#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getIntersectionNode2.py
@Function: 两个链表的第一个公共节点
@Link: https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
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
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        node1, node2 = headA, headB

        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA

        return node1


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
