#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reverseList2.py
@Function: 反转链表
@Link: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
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
    def reverseList(self, head: ListNode) -> ListNode:
        cur, pre = head, None
        while cur:
            tmp = cur.next  # 暂存后继节点 cur.next
            cur.next = pre  # 修改 next 引用指向
            pre = cur      # pre 暂存 cur
            cur = tmp      # cur 访问下一节点
        return pre


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
