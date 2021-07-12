#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: combinationSum2.py
@Function: 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
@Link: https://leetcode-cn.com/problems/combination-sum-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-12
"""

import collections
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(pos: int, rest: int):
            nonlocal sequence
            if rest == 0:
                ans.append(sequence[:])
                return
            if pos == len(freq) or rest < freq[pos][0]:
                return

            dfs(pos + 1, rest)

            most = min(rest // freq[pos][0], freq[pos][1])
            for i in range(1, most + 1):
                sequence.append(freq[pos][0])
                dfs(pos + 1, rest - i * freq[pos][0])
            sequence = sequence[:-most]

        freq = sorted(collections.Counter(candidates).items())
        ans = list()
        sequence = list()
        dfs(0, target)
        return ans


#  ------------------------
if __name__ == "__main__":
    # candidates = [10, 1, 2, 7, 6, 1, 5]
    # target = 8

    candidates = [2,5,2,1,2]
    target = 5

    solution = Solution()
    list_combine = solution.combinationSum2(candidates, target)
    print(f"The solutio of this problem is : {list_combine}")
