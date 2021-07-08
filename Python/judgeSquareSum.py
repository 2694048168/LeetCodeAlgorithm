#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: judgeSquareSum.py
@Function: 平方数之和
@Link: https://leetcode-cn.com/problems/sum-of-square-numbers/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-07
"""

import math

class Solution:
    def judgeSquareSum(self, c):
        if c == 0:
            return True

        # ---------------------------------
        # for a in range(1, int(math.sqrt(c) + 1)):
        #     b = c - a**2
        #     if int(math.sqrt(b))**2 == b:
        #         return True
        # ---------------------------------

        # ---------------------------------
        # 双指针策略
        # ---------------------------------
        left, right = 0, int(math.sqrt(c))
        while left <= right:
            sum = left**2 + right**2
            if sum == c:
                return True
            elif sum > c:
                right -= 1
            else:
                left += 1
        # ---------------------------------
        return False


# -------------------------
if __name__ == "__main__":
    c = 5

    solution = Solution()
    check = solution.judgeSquareSum(c)
    print(check)