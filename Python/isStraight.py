#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isStraight.py
@Function: 扑克牌中的顺子
@Link: https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-17
"""


from typing import List


class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        repeat = set()
        ma, mi = 0, 14
        for num in nums:
            if num == 0:
                continue  # 跳过大小王
            ma = max(ma, num)  # 最大牌
            mi = min(mi, num)  # 最小牌
            if num in repeat:
                return False  # 若有重复，提前返回 false
            repeat.add(num)  # 添加牌至 Set
        return ma - mi < 5  # 最大牌 - 最小牌 < 5 则可构成顺子


# -------------------------
if __name__ == "__main__":
    # nums = [0, 0, 1, 2, 5]
    nums = [8, 0, 1, 2, 5]

    solution = Solution()
    check_straight = solution.isStraight(nums)
    print(f"The solution of this problem is {check_straight}")
