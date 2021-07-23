#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: rotateImage.py
@Function: 旋转图像
@Link: https://leetcode-cn.com/problems/rotate-image/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-23
"""


from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n // 2):
            for j in range((n + 1) // 2):
                matrix[i][j], matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1] \
                    = matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1], matrix[i][j]


# --------------------------------------
if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    solution = Solution()
    solution.rotate(matrix)
    print(f"The solution of this problem is\n : {matrix}")
