#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: canJump.py
@Function: 跳跃游戏
@Link: https://leetcode-cn.com/problems/jump-game/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-24
"""

from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
        return False


# -------------------------
if __name__ == "__main__":
    # nums = [2, 3, 1, 1, 4]
    nums = [3, 2, 1, 0, 4]

    solution = Solution()
    check_jump = solution.canJump(nums)
    print(f"The solution of this problem is {check_jump}")
