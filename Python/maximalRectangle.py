#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maximalRectangle.py
@Function: 最大矩形
@Link: https://leetcode-cn.com/problems/maximal-rectangle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-14
"""

from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        # 记录当前位置上方连续“1”的个数
        pre = [0]*(n+1)
        res = 0
        for i in range(m):
            for j in range(n):
                # 前缀和
                pre[j] = pre[j]+1 if matrix[i][j] == "1" else 0

            # 单调栈
            stack = [-1]
            for k, num in enumerate(pre):
                while stack and pre[stack[-1]] > num:
                    index = stack.pop()
                    res = max(res, pre[index]*(k-stack[-1]-1))
                stack.append(k)

        return res


# ----------------------------------
if __name__ == "__main__":
    matrix = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"],
              ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]

    solution = Solution()
    max_area_maxtrix = solution.maximalRectangle(matrix)
    print(f"The solution of this problem is {max_area_maxtrix}")
