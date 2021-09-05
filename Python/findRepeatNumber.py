#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findRepeatNumber.py
@Function: 数组中重复的数字
@Link: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-05
"""


from typing import List


class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
                return nums[i]
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
            
        return -1


# ----------------------------------
if __name__ == "__main__":
    nums = [2, 3, 1, 0, 2, 5, 3]

    solution = Solution()
    repeat_number = solution.findRepeatNumber(nums)
    print(f"The solution of this problem is : {repeat_number}")
