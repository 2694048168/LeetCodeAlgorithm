#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: copyRandomList.py
@Function: 复杂链表的复制
@Link: https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-04
"""


from typing import List


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return
        cur = head
        # 1. 复制各节点，并构建拼接链表
        while cur:
            tmp = Node(cur.val)
            tmp.next = cur.next
            cur.next = tmp
            cur = tmp.next
        # 2. 构建各新节点的 random 指向
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        # 3. 拆分两链表
        cur = res = head.next
        pre = head
        while cur.next:
            pre.next = pre.next.next
            cur.next = cur.next.next
            pre = pre.next
            cur = cur.next
        pre.next = None  # 单独处理原链表尾节点
        return res      # 返回新链表头节点


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
