#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: productExceptSelf.py
@Function: 除自身以外数组的乘积 数学问题
@Link: https://leetcode-cn.com/problems/product-of-array-except-self/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""


from typing import  List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        answer = [0]*length

        # answer[i] 表示索引 i 左侧所有元素的乘积
        # 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1
        for i in range(1, length):
            answer[i] = nums[i - 1] * answer[i - 1]

        # R 为右侧所有元素的乘积
        # 刚开始右边没有元素，所以 R = 1
        R = 1
        for i in reversed(range(length)):
            # 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R
            # R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i]

        return answer


# ----------------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 4]

    solution = Solution()
    product_self = solution.productExceptSelf(nums)
    print(f"The solution of this problem is : {product_self}")
