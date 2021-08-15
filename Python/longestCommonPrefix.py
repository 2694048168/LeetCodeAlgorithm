#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestCommonPrefix.py
@Function: 最长公共前缀
@Link: https://leetcode-cn.com/problems/longest-common-prefix/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-15
"""

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        prefix, count = strs[0], len(strs)
        for i in range(1, count):
            prefix = self.lcp(prefix, strs[i])
            if not prefix:
                break

        return prefix

    def lcp(self, str1, str2):
        length, index = min(len(str1), len(str2)), 0
        while index < length and str1[index] == str2[index]:
            index += 1
        return str1[:index]


# --------------------------------------
if __name__ == "__main__":
    strs = ["flower", "flow", "flight"]

    solution = Solution()
    longest_prefix = solution.longestCommonPrefix(strs)
    print(f"The solutio of this problem is : {longest_prefix}")
