#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isPalindromeCheck.py
@Function: 验证回文串
@Link: https://leetcode-cn.com/problems/valid-palindrome/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-26
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        left, right = 0, n - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if left < right:
                if s[left].lower() != s[right].lower():
                    return False
                left, right = left + 1, right - 1

        return True


# --------------------------
if __name__ == "__main__":
    # str = "A man, a plan, a canal: Panama"
    str = "race a car"

    solution = Solution()
    check_palindrome = solution.isPalindrome(str)
    print(f"The solution of this problem is {check_palindrome}")
