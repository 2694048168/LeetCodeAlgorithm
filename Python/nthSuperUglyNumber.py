#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: nthSuperUglyNumber.py
@Function: 超级丑数
@Link: https://leetcode-cn.com/problems/super-ugly-number/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


import heapq

class Solution:
    def nthSuperUglyNumber(self, n, primes):
        hq = [1]
        ret = 1
        for i in range(n):
            tmp = heapq.heappop(hq)
            while hq and hq[0] == tmp:
                heapq.heappop(hq)
            for p in primes:
                heapq.heappush(hq, p * tmp)
            ret = tmp
        return ret


# -------------------------
if __name__ == "__main__":
    n = 12
    primes = [2,7,13,19]

    solution = Solution()
    super_ugly_number = solution.nthSuperUglyNumber(n, primes)
    print(f"The solution of this problem is {super_ugly_number}")
