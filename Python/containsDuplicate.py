#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: containsDuplicate.py
@Function: 存在重复元素
@Link: https://leetcode-cn.com/problems/contains-duplicate/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""

from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(list(set(nums))) != len(nums)


# -------------------------
if __name__ == "__main__":
    # nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    nums = [1, 2, 3, 4]

    solution = Solution()
    check_duplicate = solution.containsDuplicate(nums)
    print(f"The solution of this problem is {check_duplicate}")
