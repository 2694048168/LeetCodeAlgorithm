#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: spiralOrder.py
@Function: 顺时针打印矩阵
@Link: https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-26
"""

from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return list()

        rows, columns = len(matrix), len(matrix[0])
        order = list()
        left, right, top, bottom = 0, columns - 1, 0, rows - 1
        while left <= right and top <= bottom:
            for column in range(left, right + 1):
                order.append(matrix[top][column])
            for row in range(top + 1, bottom + 1):
                order.append(matrix[row][right])
            if left < right and top < bottom:
                for column in range(right - 1, left, -1):
                    order.append(matrix[bottom][column])
                for row in range(bottom, top, -1):
                    order.append(matrix[row][left])
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
        return order


# --------------------------
if __name__ == "__main__":
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]

    solution = Solution()
    spiral_order = solution.spiralOrder(matrix)
    print(f"The solution of this problem is \n{spiral_order}")
