#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestIncreasingPath.py
@Function: 矩阵中的最长递增路径
@Link: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-01
"""

from typing import List
from functools import lru_cache


class Solution:

    DIRS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        @lru_cache(None)
        def dfs(row: int, column: int) -> int:
            best = 1
            for dx, dy in Solution.DIRS:
                newRow, newColumn = row + dx, column + dy
                if 0 <= newRow < rows and 0 <= newColumn < columns and matrix[newRow][newColumn] > matrix[row][column]:
                    best = max(best, dfs(newRow, newColumn) + 1)
            return best

        ans = 0
        rows, columns = len(matrix), len(matrix[0])
        for i in range(rows):
            for j in range(columns):
                ans = max(ans, dfs(i, j))
        return ans


# ----------------------------------
if __name__ == "__main__":
    matrix = [[3, 4, 5], [3, 2, 6], [2, 2, 1]]

    solution = Solution()
    longest_increasing_path = solution.longestIncreasingPath(matrix)
    print(f"The solution of this problem is {longest_increasing_path}")
