#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: num_components.py
@Funciton Description:
@Paper arXiv:
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/10/12 16:30:08
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""给定链表头结点 head, 该链表上的每个结点都有一个 唯一的整型值
 * 同时给定列表 nums, 该列表是上述链表中整型值的一个子集。
 * 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 nums 中）构成的集合。
 *
 * solution: 计算组件的起始位置
 * 需要计算组件的个数，只需在链表中计算有多少组件的起始位置即可
 * 当一个节点满足以下条件之一时，它是组件的起始位置：
 * 1. 节点的值在数组 nums 中且节点位于链表起始位置；
 * 2. 节点的值在数组 nums 中且节点的前一个点不在数组 nums 中
 * 3. 遍历链表，计算出满足条件的点的个数即可
 *
 * 因为需要多次判断值是否位于数组 nums 中，
 * 用一个哈希集合保存数组 nums 中的点可以降低时间复杂度
"""
class Solution:
    def numComponents(self, head, nums):
        numsSet = set(nums)
        inSet = False
        res = 0
        while head:
            if head.val not in numsSet:
                inSet = False
            elif not inSet:
                inSet = True
                res += 1
            head = head.next
        return res


# ---------------------------
if __name__ == "__main__":
    nums = [0,3,1,4]
    # head = [0,1,2,3,4]
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

    head.val = 0
    second.val = 1
    third.val = 2
    forth.val = 3
    fivth.val = 4

    solution = Solution()
    num_components = solution.numComponents(head, nums)
    print(f"The solution of this problem is : {num_components}")
