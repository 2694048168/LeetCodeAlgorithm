#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: oddEvenList.py
@Function: 奇偶链表
@Link: https://leetcode-cn.com/problems/odd-even-linked-list/
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
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        evenHead = head.next
        odd, even = head, evenHead
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        odd.next = evenHead
        return head


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
