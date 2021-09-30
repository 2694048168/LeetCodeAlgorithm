#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isMatchRegular.py
@Function: 正则表达式匹配
@Link: https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-30
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)

        def matches(i: int, j: int) -> bool:
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2]
                    if matches(i, j - 1):
                        f[i][j] |= f[i - 1][j]
                else:
                    if matches(i, j):
                        f[i][j] |= f[i - 1][j - 1]
        return f[m][n]


# ----------------------------
if __name__ == "__main__":
    s = "aaA"
    p = "a*"

    solution = Solution()
    check_match_regular = solution.isMatch(s, p)
    print(f"The solution of this problem is {check_match_regular}")
