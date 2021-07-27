#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findLHS.py
@Function: 最长和谐子序列
@Link: https://leetcode-cn.com/problems/longest-harmonious-subsequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


from typing import List

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        dicts={}
        for i in nums:
            dicts[i]=dicts.get(i,0)+1
        res=0
        for i in dicts:
            if i+1 in dicts:
                res=max(res,dicts[i]+dicts[i+1])
        return res


# -------------------------
if __name__ == "__main__":
    nums = [1,3,2,2,5,2,3,7]

    solution = Solution()
    find_lhs = solution.findLHS(nums)
    print(f"The solution of this problem is {find_lhs}")
