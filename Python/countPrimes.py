#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: countPrimes.py
@Function: 计数质数 数学问题
@Link: https://leetcode-cn.com/problems/count-primes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-18
"""

""" 
/**数学问题
 * 1. 公倍数和公因数
 * 利用辗转相除法，求解两个数的最大公因数 greatest common divisor， gcd；
 * 将两个数相乘后再除以最大公因数即可得到最小公倍数 least common multiple, lcm；
 * 同时利用扩展欧几里得算法求解最大公因数的同时获取对应的系数；
 * 
 * 2. 质数(素数)
 * 针对大于 1 的自然数，除了 1 和本身之外不再有其他因数的自然数，素数；
 * 每一个数都可以分解为质数的乘积
 * 
 */
"""


class Solution:
    def countPrimes(self, n: int) -> int:
        n -= 1
        if n < 2:
            return 0
        r = int(n ** 0.5)
        V = [n//d for d in range(1, r + 1)]
        V += list(range(V[-1] - 1, 0, -1))

        S = {v: v - 1 for v in V}
        # print(S)
        for p in range(2, r + 1):
            if S[p] == S[p - 1]:
                continue
            p2 = p * p
            sp_1 = S[p - 1]
            for v in V:
                if v < p2:
                    break
                S[v] -= S[v//p] - sp_1
            # print(S)
        return S[n]


# ----------------------------------
if __name__ == "__main__":
    n = 10

    solution = Solution()
    num_primes = solution.countPrimes(n)
    print(f"The solution of this problem is : {num_primes}")
