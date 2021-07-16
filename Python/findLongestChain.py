#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findLongestChain.py
@Function: 最长数对链  动态规划
@Link: https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution(object):  # Time Limit Exceeded
    def findLongestChain(self, pairs):
        pairs.sort()
        dp = [1] * len(pairs)

        for j in range(len(pairs)):
            for i in range(j):
                if pairs[i][1] < pairs[j][0]:
                    dp[j] = max(dp[j], dp[i] + 1)

        return max(dp)


# -------------------------
if __name__ == "__main__":
    pairs = [[1,2], [2,3], [3,4]]

    solution = Solution()
    max_chain = solution.findLongestChain(pairs)
    print(f"The solution of this problem is {max_chain}")
