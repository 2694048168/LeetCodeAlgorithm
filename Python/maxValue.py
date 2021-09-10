#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxValue.py
@Function: 礼物的最大价值
@Link: https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-10
"""

from typing import List


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for j in range(1, n):  # 初始化第一行
            grid[0][j] += grid[0][j - 1]
        for i in range(1, m):  # 初始化第一列
            grid[i][0] += grid[i - 1][0]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j])
        return grid[-1][-1]


# ----------------------------------
if __name__ == "__main__":
    grid = [[1, 3, 1],
            [1, 5, 1],
            [4, 2, 1]]

    solution = Solution()
    max_value = solution.maxValue(grid)
    print(f"The solution of this problem is: {max_value}")
