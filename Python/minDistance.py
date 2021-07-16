#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minDistance.py
@Function: 编辑距离 动态规划
@Link: https://leetcode-cn.com/problems/edit-distance/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        # 有一个字符串为空串
        if n * m == 0:
            return n + m

        # DP 数组
        D = [[0] * (m + 1) for _ in range(n + 1)]

        # 边界状态初始化
        for i in range(n + 1):
            D[i][0] = i
        for j in range(m + 1):
            D[0][j] = j

        # 计算所有 DP 值
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                left = D[i - 1][j] + 1
                down = D[i][j - 1] + 1
                left_down = D[i - 1][j - 1]
                if word1[i - 1] != word2[j - 1]:
                    left_down += 1
                D[i][j] = min(left, down, left_down)

        return D[n][m]


# --------------------------
if __name__ == "__main__":
    word1, word2 = "horse", "ros"
    # word1, word2 = "intention", "execution"

    solution = Solution()
    min_distance = solution.minDistance(word1, word2)
    print(f"The solution of this problem is {min_distance}")
