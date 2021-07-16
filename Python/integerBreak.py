#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: integerBreak.py
@Function: 整数拆分  动态规划
@Link: https://leetcode-cn.com/problems/integer-break/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1

        dp = [0] * (n + 1)
        dp[2] = 1
        for i in range(3, n + 1):
            dp[i] = max(2 * (i - 2), 2 * dp[i - 2], 3 * (i - 3), 3 * dp[i - 3])

        return dp[n]


# -------------------------
if __name__ == "__main__":
    n = 2

    solution = Solution()
    max_mul = solution.integerBreak(n)
    print(f"The solution of this problem is {max_mul}")
