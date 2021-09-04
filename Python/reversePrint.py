#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reversePrint.py
@Function: 从尾到头打印链表
@Link: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-04
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        return stack[::-1]


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
