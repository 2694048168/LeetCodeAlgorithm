#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: setZeroes.py
@Function: 矩阵置零
@Link: https://leetcode-cn.com/problems/set-matrix-zeroes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-30
"""

from typing import List
import collections


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = collections.defaultdict(list)

        for st in strs:
            counts = [0] * 26
            for ch in st:
                counts[ord(ch) - ord("a")] += 1
            # 需要将 list 转换成 tuple 才能进行哈希
            mp[tuple(counts)].append(st)

        return list(mp.values())


# -------------------------
if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

    solution = Solution()
    group_anagram = solution.groupAnagrams(strs)
    print(f"The solution of this problem is : \n{group_anagram}")
