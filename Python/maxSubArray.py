#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxSubArray.py
@Function: 最大子序和  动态规划
@Link: https://leetcode-cn.com/problems/maximum-subarray/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        size = len(nums)
        pre = 0
        res = nums[0]
        for i in range(size):
            pre = max(nums[i], pre + nums[i])
            res = max(res, pre)
        return res


# -------------------------
if __name__ == "__main__":
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

    solution = Solution()
    max_sum = solution.maxSubArray(nums)
    print(f"The solution of this problem is {max_sum}")
