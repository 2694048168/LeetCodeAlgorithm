#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isIsomorphic.py
@Function: 同构字符串
@Link: https://leetcode-cn.com/problems/isomorphic-strings/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-28
"""


class Solution:
    def isIsomorphic(self, s, t):
        x = {}
        y = {}
        for i in range(len(s)):
            if (s[i] in x and x[s[i]] != t[i]) or (
                    t[i] in y and y[t[i]] != s[i]):
                return False
            x[s[i]] = t[i]
            y[t[i]] = s[i]
        return True


# ----------------------------------
if __name__ == "__main__":
    s = "paper"
    t = "title"

    solution = Solution()
    check_isomorphic = solution.isIsomorphic(s, t)
    print(f"The solution of this problem is : {check_isomorphic}")
