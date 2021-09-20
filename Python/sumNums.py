#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: sumNums.py
@Function: 求1+2+…+n
@Link: https://leetcode-cn.com/problems/qiu-12n-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-20
"""


from typing import List


class Solution:
    def __init__(self):
        self.res = 0

    def sumNums(self, n: int) -> int:
        n > 1 and self.sumNums(n - 1)
        self.res += n
        return self.res


# -------------------------
if __name__ == "__main__":
    # number = 9
    # number = 6
    number = 3

    solution = Solution()
    sum_number = solution.sumNums(number)
    print(f"The solutino of this problem is {sum_number}")
