#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxArea.py
@Function: 盛最多水的容器
@Link: https://leetcode-cn.com/problems/container-with-most-water/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-08
"""

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        maxArea = 0
        while left < right:
            area = min(height[left], height[right]) * (right - left)
            maxArea = max(maxArea, area)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1

        return maxArea


# -------------------------
if __name__ == "__main__":
    height = [4,3,2,1,4]

    solution = Solution()
    max_area = solution.maxArea(height)
    print(f"The solution of this problem is : {max_area}")
