#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: dices_probability.py
@Function: n个骰子的点数, 动态规划进行算法的设计和分析
@Link: https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-06-30
"""


class Solution:
    def dicesProbability(self, n):
        probability = 1.0 / 6.0
        # base case
        dp_list = [probability] * 6

        for i in range(2, n + 1):
            temp = [0.0] * (5 * i + 1)
            # 遍历上一次概率解列表
            for j in range(len(dp_list)):
                for k in range(6):
                    temp[j+k] += dp_list[j] * probability
            
            dp_list = temp

        return dp_list


# ----------------------------------
if __name__ == "__main__":
    num_saizi = 2

    solution = Solution()
    probability_list = solution.dicesProbability(num_saizi)

    print(probability_list)