#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: arrayPairSum.py
@Function: 数组拆分 I
@Link: https://leetcode-cn.com/problems/array-partition-i/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-18
"""

from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])


# ----------------------------------
if __name__ == "__main__":
    # nums = [6, 2, 6, 5, 1, 2]
    nums = [1, 4, 3, 2]

    solution = Solution()
    pair_max_sum = solution.arrayPairSum(nums)
    print(f"The solution of this problem is {pair_max_sum}")
