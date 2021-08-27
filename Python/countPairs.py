#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: countPairs.py
@Function: 统计点对的数目
@Link: https://leetcode-cn.com/problems/count-pairs-of-nodes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-27
"""


from typing import List
from collections import Counter


class Solution:
    def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
        # step1: initialize degrees[] and adjacent{}: (i, j) -> int
        # time: O(|edges|) = O(10^5); space: O(|edges|)
        degrees = [0] * n
        adjacent = Counter()
        for i, [p1, p2] in enumerate(edges):
            if p1 > p2:
                p1, p2 = p2, p1
            degrees[p1-1] += 1
            degrees[p2-1] += 1
            adjacent[p1-1, p2-1] += 1

        # step2: sort degrees[]
        # time: O(nlogn); space: O(nlogn) (unsure)
        degree_sorted = sorted(degrees)

        # step3: get answers
        # core idea:
        # nums(i, j) = degrees[i] + degrees[j] - adjacent[i, j]
        # if nums(i, j) >= queries[k], ans[k] += 1
        ans = [0] * len(queries)
        # time: O(|queries|) = 20
        for k, q in enumerate(queries):
            # step 3.1: use two pointers to find the numbers of (i, j) that degrees[i] + degrees[j] >= q
            # time: O(n) = 2*10^4
            left = 0
            right = len(degree_sorted) - 1
            while left < right:
                if degree_sorted[left] + degree_sorted[right] <= q:
                    left += 1
                else:
                    ans[k] += right - left
                    right -= 1
            # step 3.2: remove those that degrees[i] + degrees[j] - adjacent[i, j] < q
            # time: O(|edges|) = 10^5
            visited = set()
            for p1, p2 in adjacent:
                if (p1, p2) not in visited and degrees[p1] + degrees[p2] > q and degrees[p1] + degrees[p2] - adjacent[p1, p2] <= q:
                    ans[k] -= 1
        return ans


# --------------------------
if __name__ == "__main__":
    n = 5
    edges = [[1, 5], [1, 5], [3, 4], [2, 5], [1, 3], [5, 1], [2, 3], [2, 5]]
    queries = [1, 2, 3, 4, 5]

    solution = Solution()
    count_pairs = solution.countPairs(n, edges, queries)
    print(f"The solution of this problem is : {count_pairs}")
