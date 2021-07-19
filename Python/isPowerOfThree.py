#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isPowerOfThree.py
@Function: 3的幂 数学问题
@Link: https://leetcode-cn.com/problems/power-of-three/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-19
"""


import math

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False

        res = round(math.log(n, 3), 9)
        # python 需要精确到小数点 9 位，才能精确判断小数和它转换后的整数是否相等
        return res - round(res) == 0    # round不加第二个参数，默认保留为整数


# ----------------------------------
if __name__ == "__main__":
    # num = 21
    num = 27

    solution = Solution()
    bool_power_three = solution.isPowerOfThree(num)
    print(f"The solution of this problem is {bool_power_three}")