#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: deleteDuplicates.py
@Function: 删除排序链表中的重复元素
@Link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head

        cur = head
        while cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next

        return head


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
