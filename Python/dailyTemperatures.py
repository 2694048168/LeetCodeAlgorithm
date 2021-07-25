#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: dailyTemperatures.py
@Function: 每日温度
@Link: https://leetcode-cn.com/problems/daily-temperatures/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-25
"""

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        length = len(temperatures)
        ans = [0] * length
        stack = []
        for i in range(length):
            temperature = temperatures[i]
            while stack and temperature > temperatures[stack[-1]]:
                prev_index = stack.pop()
                ans[prev_index] = i - prev_index
            stack.append(i)
        return ans


# --------------------------------------
if __name__ == "__main__":
    temperatures = [30,40,50,60]

    solution = Solution()
    daily_temperature = solution.dailyTemperatures(temperatures)
    print(f"The solution of this problem is {daily_temperature}")
