#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: searchNumber.py
@Function: 在排序数组中查找数字 I 统计一个数字在排序数组中出现的次数
@Link: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-05
"""

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def helper(tar):
            i, j = 0, len(nums) - 1
            while i <= j:
                m = (i + j) // 2
                if nums[m] <= tar:
                    i = m + 1
                else:
                    j = m - 1
            return i
        return helper(target) - helper(target - 1)


# ----------------------------------
if __name__ == "__main__":
    # nums = [5, 7, 7, 8, 8, 10]
    # target = 6
    nums = [5, 7, 7, 8, 8, 10]
    target = 8

    solution = Solution()
    count_target = solution.search(nums, target)
    print(f"The solution of this problem is : {count_target}")
