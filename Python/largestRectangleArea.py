#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: largestRectangleArea.py
@Function: 柱状图中最大的矩形
@Link: https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-13
"""


from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = [0] * n, [n] * n

        mono_stack = list()
        for i in range(n):
            while mono_stack and heights[mono_stack[-1]] >= heights[i]:
                right[mono_stack[-1]] = i
                mono_stack.pop()
            left[i] = mono_stack[-1] if mono_stack else -1
            mono_stack.append(i)

        ans = max((right[i] - left[i] - 1) * heights[i]
                  for i in range(n)) if n > 0 else 0
        return ans


# --------------------------
if __name__ == "__main__":
    # heights = [2, 1, 5, 6, 2, 3]
    heights = [2, 4]

    solution = Solution()
    max_area = solution.largestRectangleArea(heights)
    print(f"The solution of this problem is {max_area}")
