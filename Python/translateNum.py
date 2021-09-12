#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: translateNum.py
@Function: 把数字翻译成字符串
@Link: https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-12
"""


class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        a = b = 1
        for i in range(2, len(s) + 1):
            a, b = (a + b if "10" <= s[i - 2:i] <= "25" else a), a
        return a


# ----------------------------------
if __name__ == "__main__":
    number = 12258

    solution = Solution()
    ways_translate_number = solution.translateNum(number)
    print(f"The solution of this problem is : {ways_translate_number}")
