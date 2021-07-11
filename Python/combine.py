#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: combine.py
@Function: 组合 回溯算法
@Link: https://leetcode-cn.com/problems/combinations/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""


class Solution:
    def combine(self, n, k):
        # 排列组合的性质:C(m,n)=C(m-1,n)+C(m-1,n-1)
        if k > n or k == 0:
            return []
        if k == 1:
            return [[i] for i in range(1, n+1)]
        if k == n:
            return [[i for i in range(1, n+1)]]
        res = self.combine(n-1, k)
        for item in self.combine(n-1, k-1):
            item.append(n)
            res.append(item)
        return res


# -------------------------
if __name__ == "__main__":
    n, k = 4, 2

    solution = Solution()
    combine_list = solution.combine(n, k)
    print(f"The solution of this problem is : {combine_list}")
