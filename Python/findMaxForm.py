#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findMaxForm.py
@Function: 一和零 背包问题 - 动态规划
@Link: https://leetcode-cn.com/problems/ones-and-zeroes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""

from typing import List

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]  # 默认初始化 0
        # 遍历物品
        for str in strs:
            ones = str.count('1')
            zeros = str.count('0')
            # 遍历背包容量且从后向前遍历！
            for i in range(m, zeros - 1, -1):
                for j in range(n, ones - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[m][n]


# --------------------------
if __name__ == "__main__":
    strs = ["10", "0001", "111001", "1", "0"]
    m, n = 5, 3

    solution = Solution()
    max_form = solution.findMaxForm(strs, m, n)
    print(f"The solution of this problem is {max_form}")
