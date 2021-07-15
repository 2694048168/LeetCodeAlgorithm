#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestCommonSubsequence.py
@Function: 最长公共子序列 动态规划
@Link: https://leetcode-cn.com/problems/longest-common-subsequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]


# --------------------------
if __name__ == "__main__":
    # text1 = "abcde"
    # text2 = "ace"

    text1 = "abc"
    text2 = "abc"

    # text1 = "abc"
    # text2 = "def"

    solution = Solution()
    max_length = solution.longestCommonSubsequence(text1, text2)
    print(f"The solution of this problem is {max_length}")
