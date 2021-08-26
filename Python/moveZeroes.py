#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: moveZeroes.py
@Function: 移动零
@Link: https://leetcode-cn.com/problems/move-zeroes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-26
"""

from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        left = right = 0
        while right < n:
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1


# --------------------------
if __name__ == "__main__":
    nums = [0, 1, 0, 3, 12]

    solution = Solution()
    print(f"----Processing before: {nums}")
    solution.moveZeroes(nums)
    print(f"----Processing after: {nums}")
