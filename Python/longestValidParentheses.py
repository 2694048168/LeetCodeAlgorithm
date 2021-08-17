#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestValidParentheses.py
@Function: 最长有效括号
@Link: https://leetcode-cn.com/problems/longest-valid-parentheses/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-17
"""


from typing import List


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        res = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    res = max(res, i - stack[-1])
        return res


# -------------------------
if __name__ == "__main__":
    str = ")()())"

    solution = Solution()
    longest_valid_parenttheses = solution.longestValidParentheses(str)
    print(f"The solution of this problem is {longest_valid_parenttheses}")
