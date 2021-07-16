#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: rob2.py
@Function: 打家劫舍 II  动态规划
@Link: https://leetcode-cn.com/problems/house-robber-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def rob(self, nums) -> int:
        def robRange(start: int, end: int) -> int:
            first = nums[start]
            second = max(nums[start], nums[start + 1])
            for i in range(start + 2, end + 1):
                first, second = second, max(first + nums[i], second)
            return second

        length = len(nums)
        if length == 1:
            return nums[0]
        elif length == 2:
            return max(nums[0], nums[1])
        else:
            return max(robRange(0, length - 2), robRange(1, length - 1))


# -------------------------
if __name__ == "__main__":
    nums = [2, 3, 2]

    solution = Solution()
    max_cash = solution.rob(nums)
    print(f"The solution of this problem is {max_cash}")
