#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: middle_node.py
@Funciton Description: 链表的中间结点
@LeetCode link: https://leetcode.cn/problems/middle-of-the-linked-list/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/09/26 13:33:00
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        ptr_slow, ptr_fast = head, head
        while ptr_fast and ptr_fast.next:
            ptr_fast = ptr_fast.next.next
            ptr_slow = ptr_slow.next

        return ptr_slow


# ----------------------------------
if __name__ == "__main__":
    head = ListNode()
    second = ListNode()
    third = ListNode()
    forth = ListNode()
    fivth = ListNode()

    head.next = second
    second.next = third
    third.next = forth
    forth.next = fivth
    fivth.next = None

    head.val = 1
    second.val = 2
    third.val = 3
    forth.val = 4
    fivth.val = 5

    solution = Solution()
    middle_node = solution.middleNode(head)
    print(f"The solution of this problem is : {middle_node.val}")
