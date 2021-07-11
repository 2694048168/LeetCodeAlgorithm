#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findCircleNum.py
@Function: 省份数量 熟悉 图 的表示方法
@Link: https://leetcode-cn.com/problems/number-of-provinces/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""

import collections

class Solution:
    def findCircleNum(self, isConnected):
        def dfs(i: int):
            for j in range(provinces):
                if isConnected[i][j] == 1 and j not in visited:
                    visited.add(j)
                    dfs(j)

        provinces = len(isConnected)
        visited = set()
        circles = 0

        for i in range(provinces):
            if i not in visited:
                dfs(i)
                circles += 1

        return circles


# 广度优先搜索
class Solution:
    def findCircleNum(self, isConnected):
        provinces = len(isConnected)
        visited = set()
        circles = 0
        
        for i in range(provinces):
            if i not in visited:
                Q = collections.deque([i])
                while Q:
                    j = Q.popleft()
                    visited.add(j)
                    for k in range(provinces):
                        if isConnected[j][k] == 1 and k not in visited:
                            Q.append(k)
                circles += 1
        
        return circles

# -------------------------
if __name__ == "__main__":
    # isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    isConnected = [[1,0,0],[0,1,0],[0,0,1]]

    solution = Solution()
    num_connected = solution.findCircleNum(isConnected)
    print(f"The solution of this problem is : {num_connected}")