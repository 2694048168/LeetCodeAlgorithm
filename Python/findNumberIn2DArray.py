#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findNumberIn2DArray.py
@Function: 二维数组中的查找
@Link: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-06
"""


from typing import List


class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        i, j = len(matrix) - 1, 0
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] > target:
                i -= 1
            elif matrix[i][j] < target:
                j += 1
            else:
                return True
        return False


# --------------------------
if __name__ == "__main__":
    matrix = [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    # target = 5
    target = 20

    solution = Solution()
    find_number_array = solution.findNumberIn2DArray(matrix, target)
    print(f"The solution of this proble is {find_number_array}")
