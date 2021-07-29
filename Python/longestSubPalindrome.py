#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestSubPalindrome.py
@Function: 最长回文子串
@Link: https://leetcode-cn.com/problems/longest-palindromic-substring/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-29
"""

class Solution:
    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1

    def longestPalindrome(self, s: str) -> str:
        start, end = 0, 0
        for i in range(len(s)):
            left1, right1 = self.expandAroundCenter(s, i, i)
            left2, right2 = self.expandAroundCenter(s, i, i + 1)
            if right1 - left1 > end - start:
                start, end = left1, right1
            if right2 - left2 > end - start:
                start, end = left2, right2
        return s[start: end + 1]


# ----------------------------------
if __name__ == "__main__":
    str = "abccccdd"

    solution = Solution()
    longest_plindrom = solution.longestPalindrome(str)
    print(f"The solution of this problem is : {longest_plindrom}")
