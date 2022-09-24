#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: inter_set.py
@Function: 两个数组的交集
@Link: https://leetcode.cn/problems/intersection-of-two-arrays/
@Python Version: 3.9.7
@Author: Wei Li (weili_yzzcq@163.com)
@Date: 2022-09-24
"""


class Solution:
    def intersection(self, nums1, nums2):
        hash_set1 = set(nums1)
        hash_set2 = set(nums2)
        return self.get_intersection(hash_set1, hash_set2)

    def get_intersection(self, hash_set1, hash_set2):
        if len(hash_set1) > len(hash_set2):
            return self.get_intersection(hash_set2, hash_set1)
        return [x for x in hash_set1 if x in hash_set2]


# ----------------------------------
if __name__ == "__main__":
    nums_1 = [4, 9, 5]
    nums_2 = [9, 4, 9, 8, 4]
    # nums_1 = [1, 2, 2, 1]
    # nums_2 = [2, 2]

    solution = Solution()
    inter_set = solution.intersection(nums_1, nums_2)
    print(f"The solution of this problem is : {inter_set}")
