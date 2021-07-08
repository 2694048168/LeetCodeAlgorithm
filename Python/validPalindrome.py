#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: validPalindrome.py
@Function: 验证回文字符串 Ⅱ 双指针 + 贪心策略
@Link: https://leetcode-cn.com/problems/valid-palindrome-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-08
"""

class Solution:
    def validPalindrome(self, s):
        def checkPalindrome(low, high):
            i, j = low, high
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True

        low, high = 0, len(s) - 1
        while low < high:
            if s[low] == s[high]: 
                low += 1
                high -= 1
            else:
                return checkPalindrome(low + 1, high) or checkPalindrome(low, high - 1)
        return True


# -------------------------
if __name__ == "__main__":
    # string = "aba"
    # string = "abca"
    string = "abcfdba"
    

    solution = Solution()
    check = solution.validPalindrome(string)
    print(f"The solution of this problem is {check}")