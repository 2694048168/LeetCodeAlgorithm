#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: rotateIromanToIntmage.py
@Function: 罗马数字转整数
@Link: https://leetcode-cn.com/problems/roman-to-integer/    
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-15
"""


class Solution:
    SymbolValues = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    def romanToInt(self, str: str) -> int:
        answer = 0;
        length_string = len(str)
        for i, ch in enumerate(str):
            value = Solution.SymbolValues[ch]
            if i < length_string - 1 and value < Solution.SymbolValues[str[i + 1]]:
                answer -= value
            else:
                answer += value
        
        return answer


# --------------------------------------
if __name__ == "__main__":
    str_roman = "MCMXCIV"
    # str_roman = "IX"

    solution = Solution()
    roman_int_number = solution.romanToInt(str_roman)
    print(f"The roman of string {str_roman} is number of int : {roman_int_number}")
#
