#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: jump.py
@Function: 跳跃游戏 II
@Link: https://leetcode-cn.com/problems/jump-game-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-19
"""

from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        maxPos, end, step = 0, 0, 0
        for i in range(n - 1):
            if maxPos >= i:
                maxPos = max(maxPos, i + nums[i])
                if i == end:
                    end = maxPos
                    step += 1
        return step


# -------------------------
if __name__ == "__main__":
    nums = [2, 3, 1, 1, 4]

    solution = Solution()
    num_jump = solution.jump(nums)
    print(f"The solution of this problem is {num_jump}")
