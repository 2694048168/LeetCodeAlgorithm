#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestPalindrome.py
@Function: 最长回文串 区分大小写
@Link: https://leetcode-cn.com/problems/longest-palindrome/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-29
"""

import collections

class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        count = collections.Counter(s)
        for v in count.values():
            ans += v // 2 * 2
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans


# ----------------------------------
if __name__ == "__main__":
    str = "abccccdd"

    solution = Solution()
    longest_palindrom = solution.longestPalindrome(str)
    print(f"The solution of this problem is : {longest_palindrom}")
