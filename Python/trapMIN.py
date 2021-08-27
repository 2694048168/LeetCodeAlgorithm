#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: trapMIN.py
@Function: 直方图的水量
@Link: https://leetcode-cn.com/problems/volume-of-histogram-lcci/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-27
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


# --------------------------
if __name__ == "__main__":
    edges = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

    solution = Solution()
    trap_num = solution.trap(edges)
    print(f"The solution of this problem is : {trap_num}")
