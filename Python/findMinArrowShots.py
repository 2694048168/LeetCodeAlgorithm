#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findMinArrowShots.py
@Function: 用最少数量的箭引爆气球 贪心策略
@Link: https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-05
"""

# --------------
class Solution:
    def findMinArrowShots(self, points):
        if not points:
            return 0

        points.sort(key=lambda balloon: balloon[1])
        position = points[0][1]
        num_shoots = 1
        for balloon in points:
            if balloon[0] > position:
                position = balloon[1]
                num_shoots += 1

        return num_shoots


# -------------------------------
if __name__ == "__main__":
    # test case
    # points = [[10,16],[2,8],[1,6],[7,12]]
    # points = [[1,2],[3,4],[5,6],[7,8]]
    # points = [[1,2],[2,3],[3,4],[4,5]]
    # points = [[2,3],[2,3]]
    points = [[1,2]]

    solution = Solution()
    num_shoots = solution.findMinArrowShots(points=points)
    print(f"The solution of this problem is : {num_shoots}")