#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numDistinct.py
@Function: 不同的子序列
@Link: https://leetcode-cn.com/problems/distinct-subsequences/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-01
"""


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        if m < n:
            return 0

        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][n] = 1

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]
                else:
                    dp[i][j] = dp[i + 1][j]

        return dp[0][0]


# ----------------------------------
if __name__ == "__main__":
    s = "babgbag"
    t = "bag"

    solution = Solution()
    num_distinct = solution.numDistinct(s, t)
    print(f"The solution of this problem is {num_distinct}")
