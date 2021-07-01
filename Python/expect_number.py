#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: expect_number.py
@Function: 期望个数的统计, 分析的结果就是计算一个数组的不同元素的个数
@Link: https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-06
"""


class Solution:
    def expectNumber(self, scores):
        return len(set(scores))


# ----------------------------------
if __name__ == "__main__":
    # case 1
    scores1 = [1, 2, 3]
    # case 2
    scores2 = [1, 1, 3]
    # case 3
    scores3 = [1, 4, 2]
    # case 4
    scores4 = [2, 3, 2]
    # case 5
    scores5 = [1, 2, 2, 2, 3, 4, 4, 5]

    solution = Solution()
    print("The unique element number of array: {}".format(solution.expectNumber(scores1)))
    print("The unique element number of array: {}".format(solution.expectNumber(scores2)))
    print("The unique element number of array: {}".format(solution.expectNumber(scores3)))
    print(f"The unique element number of array: {solution.expectNumber(scores4)}")
    print(f"The unique element number of array: {solution.expectNumber(scores5)}")