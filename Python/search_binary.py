#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: pre_order.py
@Funciton Description: 二分法查找
@LeetCode Link: https://leetcode.cn/problems/binary-search/
@Python Version: 3.10.4
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/09/29
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''


class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = (right - left) // 2 + left
            num = nums[mid]
            if num == target:
                return mid
            elif num > target:
                right = mid
            else:
                left = mid + 1
        return -1


# ----------------------------
if  __name__ == "__main__":
    # nums = [1, 3, 5, 6, 7, 9]
    # target = 3

    # nums = [-1,0,3,5,9,12]
    # target = 9

    nums = [-1,0,3,5,9,12]
    target = 2

    solution = Solution()
    answer = solution.search(nums, target)
    print(f"The solution of this problem is : {answer}")
