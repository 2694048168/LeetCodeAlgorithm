#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: firstUniqChar.py
@Function: 字符串中的第一个唯一字符
@Link: https://leetcode-cn.com/problems/first-unique-character-in-a-string/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-29
"""


from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return list()

        phoneMap = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index: int):
            if index == len(digits):
                combinations.append("".join(combination))
            else:
                digit = digits[index]
                for letter in phoneMap[digit]:
                    combination.append(letter)
                    backtrack(index + 1)
                    combination.pop()

        combination = list()
        combinations = list()
        backtrack(0)
        return combinations


# ------------------------------
if __name__ == "__main__":
    digits = "2"

    solution = Solution()
    letter_combination = solution.letterCombinations(digits)
    print(f"The solution of this problem is {letter_combination}")
