#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: setZeroes.py
@Function: 矩阵置零
@Link: https://leetcode-cn.com/problems/set-matrix-zeroes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-30
"""

from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        flag_col0 = False

        for i in range(m):
            if matrix[i][0] == 0:
                flag_col0 = True
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0

        for i in range(m - 1, -1, -1):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if flag_col0:
                matrix[i][0] = 0


# -------------------------
if __name__ == "__main__":
    matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]

    solution = Solution()
    print(f"Processing before: \n{matrix}")
    solution.setZeroes(matrix)
    print(f"Processing after: \n{matrix}")
