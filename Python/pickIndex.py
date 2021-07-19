#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: pickIndex.py
@Function: 按权重随机选择 数学问题
@Link: https://leetcode-cn.com/problems/random-pick-with-weight/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-19
"""

import random
import bisect

class Solution:
    def __init__(self, A):
        # 更新数组，用于存储累计和，即截至当前数字累计的权重
        # 例如[1, 4, 7] -> [1, 5, 12]
        for i in range(1, len(A)):
            A[i] += A[i - 1]
        self.A = A

    def pickIndex(self) -> int:
        # 随机抽取 1至self.A[-1]之间的一个整数
        target = random.randint(1, self.A[-1])
        # bisect：基于二分查找实现各种功能的库
        # bisect.bisect(A, target)， 在已经排好序的数组A中，寻找需插入target的索引位置
        # _left：有重复值时，插在相等的元素的左侧，例如[1, 5, 12]中，target取2~5时，都返回下标1
        return bisect.bisect_left(self.A, target)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
# ----------------------------------
if __name__ == "__main__":
    nums = [1, 3]

    solution = Solution(nums)
    param_1 = solution.pickIndex()
    print("The solution of this problem is: ")
    print(f"The origin : {nums}")
    print(f"The reset : {param_1}")
