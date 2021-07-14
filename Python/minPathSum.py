#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minPathSum.py
@Function: 最小路径和 二维动态规划
@Link: https://leetcode-cn.com/problems/minimum-path-sum/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-14
"""


class Solution2:
    def minPathSum(self, grid):
        if not grid or not grid[0]:
            return 0

        rows, columns = len(grid), len(grid[0])
        dp = [[0] * columns for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, columns):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, rows):
            for j in range(1, columns):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[rows - 1][columns - 1]


# 空间压缩 ---- 状态相关的只有上面和左边的
class Solution:
    def minPathSum(self, grid):
        if not grid or not grid[0]:
            return 0

        rows, columns = len(grid), len(grid[0])
        dp = [0] * columns
        for row in range(rows):
            for column in range(columns):
                if row == 0 and column == 0:
                    dp[column] = grid[row][column]
                elif row == 0:
                    dp[column] = dp[column - 1] + grid[row][column]
                elif column == 0:
                    dp[column] = dp[column] + grid[row][column]
                else:
                    dp[column] = min(dp[column - 1], dp[column]) + grid[row][column]

        return dp[columns - 1]


# --------------------------
if __name__ == "__main__":
    grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]

    solution = Solution()
    min_path_sum = solution.minPathSum(grid)
    print(f"The solution of this problem is {min_path_sum}")
