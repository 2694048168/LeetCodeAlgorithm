#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: trap.py
@Function: 接雨水
@Link: https://leetcode-cn.com/problems/trapping-rain-water/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-14
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        left, right = 0, len(height) - 1
        leftMax = rightMax = 0

        while left < right:
            leftMax = max(leftMax, height[left])
            rightMax = max(rightMax, height[right])
            if height[left] < height[right]:
                ans += leftMax - height[left]
                left += 1
            else:
                ans += rightMax - height[right]
                right -= 1

        return ans


# ----------------------------------
if __name__ == "__main__":
    # height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    height = [4, 2, 0, 3, 2, 5]

    solution = Solution()
    max_trap = solution.trap(height)
    print(f"The solution of this problem is {max_trap}")
