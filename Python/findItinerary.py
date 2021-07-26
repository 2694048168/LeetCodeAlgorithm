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
import collections
import heapq

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def dfs(curr: str):
            while vec[curr]:
                tmp = heapq.heappop(vec[curr])
                dfs(tmp)
            stack.append(curr)

        vec = collections.defaultdict(list)
        for depart, arrive in tickets:
            vec[depart].append(arrive)
        for key in vec:
            heapq.heapify(vec[key])
        
        stack = list()
        dfs("JFK")
        return stack[::-1]


# -------------------------
if __name__ == "__main__":
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]

    solution = Solution()
    find_itinerary = solution.findItinerary(tickets)
    print(f"The solution of this problem is {find_itinerary}")

