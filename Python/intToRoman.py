#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: intToRoman.py
@Function: 整数转罗马数字
@Link: https://leetcode-cn.com/problems/integer-to-roman/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-16
"""


class Solution:
    THOUSANDS = ["", "M", "MM", "MMM"]
    HUNDREDS = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
    TENS = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    ONES = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

    def intToRoman(self, num: int) -> str:
        return Solution.THOUSANDS[num // 1000] + \
            Solution.HUNDREDS[num % 1000 // 100] + \
            Solution.TENS[num % 100 // 10] + \
            Solution.ONES[num % 10]


# ----------------------------------
if __name__ == "__main__":
    number = 42

    solution = Solution()
    roman_number = solution.intToRoman(number)
    print(f"The solution of this problem is {roman_number}")
