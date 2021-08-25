#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findMaximizedCapital.py
@Function: IPO
@Link: https://leetcode-cn.com/problems/ipo/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-25
"""


from typing import List
from heapq import nlargest, heappop, heappush


class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # to speed up: if all projects are available
        if W >= max(Capital):
            return W + sum(nlargest(k, Profits))

        n = len(Profits)
        projects = [(Capital[i], Profits[i]) for i in range(n)]
        # sort the projects :
        # the most available (= the smallest capital) is the last one
        projects.sort(key=lambda x: -x[0])

        available = []
        while k > 0:
            # update available projects
            while projects and projects[-1][0] <= W:
                heappush(available, -projects.pop()[1])
            # if there are available projects,
            # pick the most profitable one
            if available:
                W -= heappop(available)
            # not enough capital to start any project
            else:
                break
            k -= 1
        return W


# -------------------------
if __name__ == "__main__":
    k = 2
    W = 0
    Profits = [1, 2, 3]
    Capital = [0, 1, 1]

    solution = Solution()
    find_max_min_capial = solution.findMaximizedCapital(k, W, Profits, Capital)
    print(f"The solution of this problem is {find_max_min_capial}")
