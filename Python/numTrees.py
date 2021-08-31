#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numTrees.py
@Function: 不同的二叉搜索树
@Link: https://leetcode-cn.com/problems/unique-binary-search-trees/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-31
"""


# 动态规划
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        G = [0]*(n+1)
        G[0], G[1] = 1, 1

        for i in range(2, n+1):
            for j in range(1, i+1):
                G[i] += G[j-1] * G[i-j]

        return G[n]


# 数学方法
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        C = 1
        for i in range(0, n):
            C = C * 2*(2*i+1)/(i+2)
        return int(C)


# --------------------------
if __name__ == "__main__":
    num = 3

    solution = Solution()
    num_trees = solution.numTrees(num)
    print(f"The solution of this problem is : {num_trees}")
