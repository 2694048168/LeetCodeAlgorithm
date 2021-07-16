#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minSteps.py
@Function: 只有两个键的键盘 动态规划
@Link: https://leetcode-cn.com/problems/2-keys-keyboard/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution(object):
    def minSteps(self, n):
        ans = 0
        d = 2
        while n > 1:
            while n % d == 0:
                ans += d
                n /= d
            d += 1
        return ans


# --------------------------
if __name__ == "__main__":
    num = 3

    solution = Solution()
    min_steps = solution.minSteps(num)
    print(f"The solution of this problem is {min_steps}")
