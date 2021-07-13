#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: rob.py
@Function: 打家劫舍 动态规划 注意处理边界条件
@Link: https://leetcode-cn.com/problems/house-robber/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-13
"""


class Solution:
    def rob(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        else:
            pre2, pre1 = 0, 0
            for i in range(n):
                current = max(pre2 + nums[i], pre1)
                pre2 = pre1
                pre1 = current
            return current


# --------------------------
if __name__ == "__main__":
    # nums = [2, 7, 9, 3, 1]
    nums = [1, 2, 3, 1]

    solution = Solution()
    num_crash = solution.rob(nums)
    print(f"The solution of this problem is : {num_crash}")
