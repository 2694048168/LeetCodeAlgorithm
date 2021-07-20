#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minMoves2.py
@Function: 最少移动次数使数组元素相等 II 数学问题
@Link: https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""


from typing import List


class Solution:
    def minMoves2(self, a: List[int]) -> int:
        a.sort()
        i, j = 0, len(a)-1
        ans = 0
        while i < j:
            ans += a[j]-a[i]
            i += 1
            j -= 1
        return ans


# ----------------------------------
if __name__ == "__main__":
    # nums = [1, 2, 3]
    nums = [1, 2, 3, 4]

    solution = Solution()
    min_move_steps = solution.minMoves2(nums)
    print(f"The solution of this problem is : {min_move_steps}")
