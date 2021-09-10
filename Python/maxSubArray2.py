#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxSubArray2.py
@Function: 连续子数组的最大和
@Link: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-10
"""


from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            nums[i] += max(nums[i - 1], 0)
        return max(nums)


# ----------------------------------
if __name__ == "__main__":
    nums = [-2,1,-3,4,-1,2,1,-5,4]

    solution = Solution()
    max_subarray_sum = solution.maxSubArray(nums)
    print(f"The solution of this problem is: {max_subarray_sum}")
