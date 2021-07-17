#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: beautifulArray.py
@Function: 漂亮数组 分治算法策略 & 动态规划策略
@Link: https://leetcode-cn.com/problems/beautiful-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-17
"""


from typing import List


class Solution:
    def beautifulArray(self, N: int) -> List[int]:
        memo = {1: [1]}

        def f(N):
            if N not in memo:
                memo[N] = [
                    2 * x - 1 for x in f((N + 1) // 2)] + [2 * x for x in f(N // 2)]
            return memo[N]
        return f(N)


# ----------------------------------
if __name__ == "__main__":
    # n = 4
    n = 5

    solution = Solution()
    beautiful_array = solution.beautifulArray(n)
    print(f"The solution of this problem is : {beautiful_array}")
