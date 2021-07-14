#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maximalSquare.py
@Function: 最大正方形 动态规划 
@Link: https://leetcode-cn.com/problems/maximal-square/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-14
"""

from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        maxSide = 0
        rows, columns = len(matrix), len(matrix[0])
        dp = [[0] * columns for _ in range(rows)]
        for i in range(rows):
            for j in range(columns):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i - 1][j], dp[i]
                                       [j - 1], dp[i - 1][j - 1]) + 1
                    maxSide = max(maxSide, dp[i][j])

        maxSquare = maxSide * maxSide

        return maxSquare


# ---------------------------------
if __name__ == "__main__":
    matrix = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"],
              ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]

    solution = Solution()
    max_area = solution.maximalSquare(matrix)
    print(f"The solution of thsi problem is {max_area}")
