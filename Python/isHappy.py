#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isHappy.py
@Function: 快乐数 数学问题
@Link: https://leetcode-cn.com/problems/happy-number/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""

from typing import List


class Solution:
    def isHappy(self, n: int) -> bool:
        cycle_members = {4, 16, 37, 58, 89, 145, 42, 20}
        def get_next(number):
            total_sum = 0
            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit ** 2
            return total_sum

        while n != 1 and n not in cycle_members:
            n = get_next(n)

        return n == 1


# ----------------------------------
if __name__ == "__main__":
    # number = 19
    number = 2

    solution = Solution()
    check_happy = solution.isHappy(number)
    print(f"The solution of this problem is : {check_happy}")
