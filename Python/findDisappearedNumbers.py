#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findDisappearedNumbers.py
@Function: 找到所有数组中消失的数字
@Link: https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-23
"""

from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for num in nums:
            x = (num - 1) % n
            nums[x] += n

        ret = [i + 1 for i, num in enumerate(nums) if num <= n]
        return ret


# --------------------------------------
if __name__ == "__main__":
    nums = [4, 3, 2, 7, 8, 2, 3, 1]

    solution = Solution()
    disappeared_vec = solution.findDisappearedNumbers(nums)
    print(f"The solution of this problem is : {disappeared_vec}")
