#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isValid.py
@Function: 有效的括号
@Link: https://leetcode-cn.com/problems/valid-parentheses/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-25
"""


class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False

        pairs = {
            ")": "(",
            "]": "[",
            "}": "{",
        }
        stack = list()
        for ch in s:
            if ch in pairs:
                if not stack or stack[-1] != pairs[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)

        return not stack


# --------------------------------------
if __name__ == "__main__":
    # s = "()[]{}"
    s = "([)]"

    solution = Solution()
    check_valid = solution.isValid(s)
    print(f"The solution of this problem is {check_valid}")