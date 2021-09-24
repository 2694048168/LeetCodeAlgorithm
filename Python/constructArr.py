#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: constructArr.py
@Function: 构建乘积数组
@Link: https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-24
"""


from typing import List


class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        b, tmp = [1] * len(a), 1
        for i in range(1, len(a)):
            b[i] = b[i - 1] * a[i - 1]  # 下三角
        for i in range(len(a) - 2, -1, -1):
            tmp *= a[i + 1]            # 上三角
            b[i] *= tmp                # 下三角 * 上三角
        return b


# ----------------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5]

    solution = Solution()
    construct_array = solution.constructArr(nums)
    print(f"The solution of this problem is : {construct_array}")
