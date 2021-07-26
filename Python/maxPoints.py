#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestConsecutive.py
@Function: 最长连续序列
@Link: https://leetcode-cn.com/problems/longest-consecutive-sequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""


from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # 三点在一条直线上时,斜率相等
        # y2 - y1 = k * (x2 - x1), y3 - y2 = k * (x3 - x2)
        # (y2 - y1) * (x3 - x2) = (y3 - y2) * (x2 - x1)

        explored = set()
        ans = 1
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                curr = 2
                dx, dy = points[j][0] - \
                    points[i][0], points[j][1] - points[i][1]
                for k in range(j+1, len(points)):
                    if (i, j) in explored or (i, k) in explored or (j, k) in explored:
                        continue
                    if dy * (points[k][0] - points[j][0]) == (points[k][1] - points[j][1]) * dx:
                        curr += 1
                        explored.add((j, k))
                        explored.add((i, k))
                ans = max(ans, curr)
        return ans


# -------------------------
if __name__ == "__main__":
    # points = [[1, 1], [2, 2], [3, 3]]
    points = [[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]

    solution = Solution()
    max_point = solution.maxPoints(points)
    print(f"The solution of this problem is {max_point}")
