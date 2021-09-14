#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: twoSum3.py
@Function: 和为s的两个数字
@Link: https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-14
"""


from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            s = nums[i] + nums[j]
            if s > target:
                j -= 1
            elif s < target:
                i += 1
            else:
                return nums[i], nums[j]
        return []


# -----------------------------------
if __name__ == "__main__":
    nums = [10, 26, 30, 31, 47, 60]
    target = 40

    solution = Solution()
    two_sum_num = solution.twoSum(nums, target)
    print(f"The solution of this problem is : {two_sum_num}")
