#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: missingNumberOnly.py
@Function: 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
           在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
@Link: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-05
"""


from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        i, j = 0, len(nums) - 1
        while i <= j:
            m = (i + j) // 2
            if nums[m] == m:
                i = m + 1
            else:
                j = m - 1
        return i


# ----------------------------------
if __name__ == "__main__":
    nums = [0, 1, 3]

    solution = Solution()
    missing_number = solution.missingNumber(nums)
    print(f"The solution of this problem is : {missing_number}")
