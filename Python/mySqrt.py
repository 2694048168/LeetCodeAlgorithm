#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: mySqrt.py
@Function: 非负整数 x 的平方根 二分查找算法
@Link: https://leetcode-cn.com/problems/sqrtx/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-08
"""


class Solution:
    def mySqrt(self, x):
        """二分查找算法"""
        left, right, ans = 0, x, -1
        while left <= right:
            mid = (left + right) // 2
            if mid * mid <= x:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans


class Solution:
    def mySqrt(self, x):
        """牛顿迭代算法"""
        if x == 0:
            return 0

        C, x0 = float(x), float(x)
        while True:
            xi = 0.5 * (x0 + C / x0)
            if abs(x0 - xi) < 1e-7:
                break
            x0 = xi

        return int(x0)


# -------------------------
if __name__ == "__main__":
    # x = 4
    # x = 5
    x = 8

    solution = Solution()
    num_sqrt = solution.mySqrt(x)
    print(f"The solution of this problem is : {num_sqrt}")