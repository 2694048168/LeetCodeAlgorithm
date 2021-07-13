#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: climbStairs.py
@Function: 爬楼梯 动态规划 注意处理边界条件
@Link: https://leetcode-cn.com/problems/climbing-stairs/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-13
"""


class Solution:
    def climbStairs(self, n):
        # 边界条件
        if n <= 2:
            return n

        pre2, pre1 = 1, 2
        for i in range(2, n):
            current = pre1 + pre2
            pre2 = pre1
            pre1 = current

        return current


# ---------------------------
if __name__ == "__main__":
    # n = 3
    n = 2

    solution = Solution()
    num_methods = solution.climbStairs(n)
    print(f"The solution of this problem is : {num_methods}")
