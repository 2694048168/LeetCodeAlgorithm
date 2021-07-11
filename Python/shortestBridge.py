#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: shortestBridge.py
@Function: 最短的桥 广度优先搜索
@Link: https://leetcode-cn.com/problems/shortest-bridge/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""

import collections


class Solution(object):
    def shortestBridge(self, A):
        R, C = len(A), len(A[0])

        def neighbors(r, c):
            for nr, nc in ((r-1, c), (r, c-1), (r+1, c), (r, c+1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc

        def get_components():
            done = set()
            components = []
            for r, row in enumerate(A):
                for c, val in enumerate(row):
                    if val and (r, c) not in done:
                        # Start dfs
                        stack = [(r, c)]
                        seen = {(r, c)}
                        while stack:
                            node = stack.pop()
                            for nei in neighbors(*node):
                                if A[nei[0]][nei[1]] and nei not in seen:
                                    stack.append(nei)
                                    seen.add(nei)
                        done |= seen
                        components.append(seen)
            return components

        source, target = get_components()
        # print(source, target)
        queue = collections.deque([(node, 0) for node in source])
        done = set(source)
        while queue:
            node, d = queue.popleft()
            if node in target:
                return d-1
            for nei in neighbors(*node):
                if nei not in done:
                    queue.append((nei, d+1))
                    done.add(nei)


# -------------------------
if __name__ == "__main__":
    # A = [[0, 1], [1, 0]]
    A = [[0, 1, 0], [0, 0, 0], [0, 0, 1]]
    # A = [[1, 1, 1, 1, 1], [1, 0, 0, 0, 1], [
    #     1, 0, 1, 0, 1], [1, 0, 0, 0, 1], [1, 1, 1, 1, 1]]

    solution = Solution()
    min_bridge = solution.shortestBridge(A)
    print(f"The solutio of this problem is : {min_bridge}")
