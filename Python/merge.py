#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: merge.py
@Function: 合并两个有序数组 双指针策略
@Link: https://leetcode-cn.com/problems/merge-sorted-array/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-07
"""

class Solution:
    def merge(self, num1, m, num2, n):
        """Do not return anything, modify nums1 in place instead.

        Args:
            num1 (list int): 整型列表 num1
            m (int): 整型列表 num1 的大小
            num2 (list int): 整型列表 num2
            n (int): 整型列表 num2 的大小
        """
        ptr1, ptr2 = m - 1, n - 1;
        ptr_tail = m + n - 1;
        while ptr1 >= 0 or ptr2 >= 0:
            if ptr1 == -1:
                num1[ptr_tail] = num2[ptr2]
                ptr2 -= 1
            elif ptr2 == -1:
                num1[ptr_tail] = num1[ptr1]
                ptr1 -= 1
            elif num1[ptr1] > num2[ptr2]:
                num1[ptr_tail] = num1[ptr1]
                ptr1 -= 1
            else:
                num1[ptr_tail] = num2[ptr2]
                ptr2 -= 1

            ptr_tail -= 1


# -------------------------
if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3

    print("------------Before merge------------")
    print(nums1)
    solution = Solution()
    solution.merge(num1=nums1, m=m, num2=nums2, n=n)
    print("------------After merge------------")
    print(nums1)