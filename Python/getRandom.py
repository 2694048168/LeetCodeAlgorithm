#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getRandom.py
@Function: 链表随机节点 数学问题
@Link: https://leetcode-cn.com/problems/linked-list-random-node/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-19
"""

import random

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        count = 0
        cur = self.head  # cur为当前节点
        while cur:
            count += 1
            # 等概率取样，每个样本被取到的概率都是1/count
            # 例如，count为1时，概率为1，即res的初值。count为2时，有1/2的几率选中2，如选中，2即为res，替换之前的res，以此类推。
            if random.randint(1, count) == count:
                res = cur.val
            cur = cur.next
        return res


# ------------------------------------------------------------------
# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
