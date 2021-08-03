#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reachableNodes.py
@Function: 细分图中的可到达结点
@Link: https://leetcode-cn.com/problems/reachable-nodes-in-subdivided-graph/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-03
"""


from typing import List
import collections
import heapq

class Solution(object):
    def reachableNodes(self, edges, M, N):
        graph = collections.defaultdict(dict)
        for u, v, w in edges:
            graph[u][v] = graph[v][u] = w

        pq = [(0, 0)]
        dist = {0: 0}
        used = {}
        ans = 0

        while pq:
            d, node = heapq.heappop(pq)
            if d > dist[node]: continue
            # Each node is only visited once.  We've reached
            # a node in our original graph.
            ans += 1

            for nei, weight in graph[node].items():
                # M - d is how much further we can walk from this node;
                # weight is how many new nodes there are on this edge.
                # v is the maximum utilization of this edge.
                v = min(weight, M - d)
                used[node, nei] = v

                # d2 is the total distance to reach 'nei' (nei***or) node
                # in the original graph.
                d2 = d + weight + 1
                if d2 < dist.get(nei, M+1):
                    heapq.heappush(pq, (d2, nei))
                    dist[nei] = d2

        # At the end, each edge (u, v, w) can be used with a maximum
        # of w new nodes: a max of used[u, v] nodes from one side,
        # and used[v, u] nodes from the other.
        for u, v, w in edges:
            ans += min(w, used.get((u, v), 0) + used.get((v, u), 0))

        return ans


# ----------------------------------
if __name__ == "__main__":
    edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]]
    maxMoves, n = 10, 4

    solution = Solution()
    reachable_nodes = solution.reachableNodes(edges, maxMoves, n)
    print(f"The solution of this problem is : {reachable_nodes}")
