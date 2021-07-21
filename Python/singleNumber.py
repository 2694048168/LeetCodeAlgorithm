#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: singleNumber.py
@Function: 只出现一次的数字
@Link: https://leetcode-cn.com/problems/single-number/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""

from typing import List
from functools import reduce


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x ^ y, nums)


# -------------------------
if __name__ == "__main__":
    nums = [2, 2, 1]
    # nums = [4, 1, 2, 1, 2]

    solution = Solution()
    single_number = solution.singleNumber(nums)
    print(f"The solution of this problem is {single_number}")
