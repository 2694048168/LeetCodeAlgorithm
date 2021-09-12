#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: deleteNode2.py
@Function: 删除链表的节点
@Link: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-12
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head.val == val:
            return head.next
        pre, cur = head, head.next
        while cur and cur.val != val:
            pre, cur = cur, cur.next
        if cur:
            pre.next = cur.next
        return head


# ----------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
