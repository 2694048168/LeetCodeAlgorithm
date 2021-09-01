#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isScramble.py
@Function: 扰乱字符串
@Link: https://leetcode-cn.com/problems/scramble-string/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-01
"""


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        if sorted(s1) != sorted(s2):
            return False

        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]) or \
                    (self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i])):
                return True
        return False


# ----------------------------------
if __name__ == "__main__":
    str1 = "abcde"
    str2 = "caebd"

    solution = Solution()
    check_is_scramble = solution.isScramble(str1, str2)
    print(f"The solution of this problem is {check_is_scramble}")
