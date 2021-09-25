#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findContinuousSequence.py
@Function: 和为s的连续正数序列
@Link: https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-25
"""


from typing import List


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i, j, s, res = 1, 2, 3, []
        while i < j:
            if s == target:
                res.append(list(range(i, j + 1)))
            if s >= target:
                s -= i
                i += 1
            else:
                j += 1
                s += j
        return res


# --------------------------------------
if __name__ == "__main__":
    number = 9

    solution = Solution()
    find_continuous_sequence = solution.findContinuousSequence(number)
    print(f"The solution of this problem is \n{find_continuous_sequence}")
