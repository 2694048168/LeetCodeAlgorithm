#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: movingCount.py
@Function: 机器人的运动范围
@Link: https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-15
"""


def dig(n):
    ans = 0
    while n:
        ans += n % 10
        n //= 10
    return ans


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        vis = set([(0, 0)])
        for i in range(m):
            for j in range(n):
                if dig(i)+dig(j) <= k and ((i-1, j) in vis or (i, j-1) in vis):
                    vis.add((i, j))
        return len(vis)


# -------------------------
if __name__ == "__main__":
    m = 3
    n = 1
    k = 0

    solution = Solution()
    moving_count = solution.movingCount(m=m, n=n, k=k)
    print(f"The solution of this problem is : {moving_count}")
