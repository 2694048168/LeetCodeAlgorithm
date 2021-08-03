#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findRedundantConnection.py
@Function: 冗余连接
@Link: https://leetcode-cn.com/problems/redundant-connection/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-03
"""


from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        nodesCount = len(edges)
        parent = list(range(nodesCount + 1))

        def find(index: int) -> int:
            if parent[index] != index:
                parent[index] = find(parent[index])
            return parent[index]

        def union(index1: int, index2: int):
            parent[find(index1)] = find(index2)

        for node1, node2 in edges:
            if find(node1) != find(node2):
                union(node1, node2)
            else:
                return [node1, node2]

        return []


# ----------------------------------
if __name__ == "__main__":
    edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]

    solution = Solution()
    find_redundant_connection = solution.findRedundantConnection(edges)
    print(f"The solution of this problem is : {find_redundant_connection}")
