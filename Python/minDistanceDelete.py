#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minDistanceDelete.py
@Function: 两个字符串的删除操作  动态规划
@Link: https://leetcode-cn.com/problems/delete-operation-for-two-strings/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # method4
        M, N = len(word1), len(word2)
        dp = [0] * (N+1)
        for i in range(1, M+1):
            temp1 = dp[0]
            for j in range(1, N+1):
                temp2 = dp[j]
                if word1[i-1] == word2[j-1]:
                    dp[j] = temp1 + 1
                else:
                    dp[j] = max(dp[j], dp[j-1])
                temp1 = temp2
        return M + N - 2 * dp[-1]


# -------------------------
if __name__ == "__main__":
    n = 2

    solution = Solution()
    max_mul = solution.integerBreak(n)
    print(f"The solution of this problem is {max_mul}")
