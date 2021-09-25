#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lastRemaining.py
@Function: 圆圈中最后剩下的数字
@Link: https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-25
"""


class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        f = 0
        for i in range(2, n + 1):
            f = (m + f) % i
        return f


# --------------------------------------
if __name__ == "__main__":
    n, m = 10, 17
    # n, m = 5, 3

    solution = Solution()
    last_remaining = solution.lastRemaining(n, m)
    print(f"The solution of this problem is {last_remaining}")
