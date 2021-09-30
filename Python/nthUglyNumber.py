#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: nthUglyNumber.py
@Function: 丑数
@Link: https://leetcode-cn.com/problems/chou-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-30
"""


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        p2 = p3 = p5 = 1

        for i in range(2, n + 1):
            num2, num3, num5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(num2, num3, num5)
            if dp[i] == num2:
                p2 += 1
            if dp[i] == num3:
                p3 += 1
            if dp[i] == num5:
                p5 += 1

        return dp[n]


# ----------------------------
if __name__ == "__main__":
    number = 10

    solution = Solution()
    n_order_uglyNumber = solution.nthUglyNumber(number)
    print(f"The solution of this problem is {n_order_uglyNumber}")
