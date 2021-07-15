#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numDecodings.py
@Function: 解码方法 动态规划
@Link: https://leetcode-cn.com/problems/decode-ways/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""


class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        f = [1] + [0] * n
        for i in range(1, n + 1):
            if s[i - 1] != '0':
                f[i] += f[i - 1]
            if i > 1 and s[i - 2] != '0' and int(s[i-2:i]) <= 26:
                f[i] += f[i - 2]
        return f[n]


class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        # a = f[i-2], b = f[i-1], c = f[i]
        a, b, c = 0, 1, 0
        for i in range(1, n + 1):
            c = 0
            if s[i - 1] != '0':
                c += b
            if i > 1 and s[i - 2] != '0' and int(s[i-2:i]) <= 26:
                c += a
            a, b = b, c
        return c


# --------------------------
if __name__ == "__main__":
    str = "12"
    # str = "226"
    # str = "06"

    solution = Solution()
    num_decodings = solution.numDecodings(str)
    print(f"The solution of this problem is {num_decodings}")
