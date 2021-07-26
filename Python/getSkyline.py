#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getSkyline.py
@Function: 天际线问题
@Link: https://leetcode-cn.com/problems/the-skyline-problem/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""

from typing import List
import heapq


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        """顺序扫描优化"""
        s = []
        ans = []
        cur = 0
        for left, right, height in buildings:
            while s and s[0][1] < left:
                rh, r = heapq.heappop(s)
                if r >= cur:
                    if not s or rh != s[0][0]:
                        while s and r > s[0][1]:
                            heapq.heappop(s)
                        rh = -s[0][0] if s else 0
                        # 避免右端点重复
                        if r == ans[-1][0]:
                            ans[-1][1] = min(ans[-1][1], rh)
                        else:
                            ans.append([r, rh])
                    cur = r
            if not s or height > -s[0][0]:
                # 避免左端点重复的问题
                if ans and left == ans[-1][0]:
                    ans[-1][1] = height
                else:
                    ans.append([left, height])
            heapq.heappush(s, [-height, right])
        while s:
            rh, r = heapq.heappop(s)
            if r >= cur:
                if not s or rh != s[0][0]:
                    while s and r > s[0][1]:
                        heapq.heappop(s)
                    rh = -s[0][0] if s else 0
                    # 避免右端点重复
                    if r == ans[-1][0]:
                        ans[-1][1] = min(ans[-1][1], rh)
                    else:
                        ans.append([r, rh])
                cur = r
        return ans


# -------------------------
if __name__ == "__main__":
    buildings = [[2, 9, 10], [3, 7, 15], [
        5, 12, 12], [15, 20, 10], [19, 24, 8]]

    solution = Solution()
    get_sky_line = solution.getSkyline(buildings)
    print(f"The solution of this problem is {get_sky_line}")
