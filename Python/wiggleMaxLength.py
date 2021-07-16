#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: wiggleMaxLength.py
@Function: 摆动序列  动态规划
@Link:https://leetcode-cn.com/problems/wiggle-subsequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def wiggleMaxLength(self, nums) -> int:
        n = len(nums)
        if n < 2:
            return n

        up = [1] + [0] * (n - 1)
        down = [1] + [0] * (n - 1)
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                up[i] = max(up[i - 1], down[i - 1] + 1)
                down[i] = down[i - 1]
            elif nums[i] < nums[i - 1]:
                up[i] = up[i - 1]
                down[i] = max(up[i - 1] + 1, down[i - 1])
            else:
                up[i] = up[i - 1]
                down[i] = down[i - 1]

        return max(up[n - 1], down[n - 1])


# -------------------------
if __name__ == "__main__":
    nums = [1, 7, 4, 9, 2, 5]

    solution = Solution()
    max_length = solution.wiggleMaxLength(nums)
    print(f"The solution of this problem is {max_length}")
