#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getKthFromEnd.py
@Function: 链表中倒数第k个节点
@Link: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
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
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast, slow = head, head

        while fast and k > 0:
            fast, k = fast.next, k - 1
        while fast:
            fast, slow = fast.next, slow.next

        return slow


# ----------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
