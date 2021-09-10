#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: fib.py
@Function: 斐波那契数列
@Link: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-10
"""

from typing import List


class Solution:
    def fib(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        if n < 2:
            return n

        def multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
            c = [[0, 0], [0, 0]]
            for i in range(2):
                for j in range(2):
                    c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD
            return c

        def matrix_pow(a: List[List[int]], n: int) -> List[List[int]]:
            ret = [[1, 0], [0, 1]]
            while n > 0:
                if n & 1:
                    ret = multiply(ret, a)
                n >>= 1
                a = multiply(a, a)
            return ret

        res = matrix_pow([[1, 1], [1, 0]], n - 1)
        return res[0][0]


# ----------------------------------
if __name__ == "__main__":
    n = 5

    solution = Solution()
    fib_number = solution.fib(n)
    print(f"The solution of this problem is: {fib_number}")

