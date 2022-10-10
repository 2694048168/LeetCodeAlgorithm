#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: min_swap.py
@Funciton Description: 使序列严格递增的最小交换次数
@Cite https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/10/10 16:42:01
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''


class Solution:
    def minSwap(self, nums1, nums2):
        n = len(nums1)
        a, b = 0, 1
        for i in range(1, n):
            at, bt = a, b
            a = b = n
            if nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]:
                a = min(a, at)
                b = min(b, bt + 1)
            if nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]:
                a = min(a, bt)
                b = min(b, at + 1)
        return min(a, b)


# -----------------------------
if __name__ == "__main__":
    nums1 = [1,3,5,4]
    nums2 = [1,2,3,7]

    solution = Solution()
    min_num_swap = solution.minSwap(nums1, nums2)
    print(f"the miniminze number of swap operators: {min_num_swap}")
