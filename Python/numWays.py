#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numWays.py
@Function: 青蛙跳台阶问题
@Link: https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-10
"""


from typing import List


class Solution:
    def numWays(self, n: int) -> int:
        cur, nxt = 1, 1
        for _ in range(n):
            cur, nxt = nxt, cur + nxt
        return cur % 1000000007


# ----------------------------------
if __name__ == "__main__":
    n = 7

    solution = Solution()
    num_ways = solution.numWays(n)
    print(f"The solution of this problem is: {num_ways}")
