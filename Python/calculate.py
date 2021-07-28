#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: calculate.py
@Function: 基本计算器 II
@Link: https://leetcode-cn.com/problems/basic-calculator-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-28
"""


class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)
        stack = []
        preSign = '+'
        num = 0
        for i in range(n):
            if s[i] != ' ' and s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if i == n - 1 or s[i] in '+-*/':
                if preSign == '+':
                    stack.append(num)
                elif preSign == '-':
                    stack.append(-num)
                elif preSign == '*':
                    stack.append(stack.pop() * num)
                else:
                    stack.append(int(stack.pop() / num))
                preSign = s[i]
                num = 0
        return sum(stack)


# ----------------------------------
if __name__ == "__main__":
    str = " 3/2 "

    solution = Solution()
    calculate_value = solution.calculate(str)
    print(f"The solution of this problem is : {calculate_value}")
