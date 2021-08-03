#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isBipartite.py
@Function: 判断二分图
@Link: https://leetcode-cn.com/problems/is-graph-bipartite/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-03
"""


from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        UNCOLORED, RED, GREEN = 0, 1, 2
        color = [UNCOLORED] * n
        valid = True

        def dfs(node: int, c: int):
            nonlocal valid
            color[node] = c
            cNei = (GREEN if c == RED else RED)
            for neighbor in graph[node]:
                if color[neighbor] == UNCOLORED:
                    dfs(neighbor, cNei)
                    if not valid:
                        return
                elif color[neighbor] != cNei:
                    valid = False
                    return

        for i in range(n):
            if color[i] == UNCOLORED:
                dfs(i, RED)
                if not valid:
                    break

        return valid


# ----------------------------------
if __name__ == "__main__":
    # graph = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
    graph = [[1, 3], [0, 2], [1, 3], [0, 2]]

    solution = Solution()
    check_bipartite = solution.isBipartite(graph)
    print(f"The solution of this problem is : {check_bipartite}")
