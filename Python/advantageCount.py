#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: advantageCount.py
@Function: 优势洗牌
@Link: https://leetcode-cn.com/problems/advantage-shuffle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


class Solution(object):
    def advantageCount(self, A, B):
        sortedA = sorted(A)
        sortedB = sorted(B)

        # assigned[b] = list of a that are assigned to beat b
        # remaining = list of a that are not assigned to any b
        assigned = {b: [] for b in B}
        remaining = []

        # populate (assigned, remaining) appropriately
        # sortedB[j] is always the smallest unassigned element in B
        j = 0
        for a in sortedA:
            if a > sortedB[j]:
                assigned[sortedB[j]].append(a)
                j += 1
            else:
                remaining.append(a)

        # Reconstruct the answer from annotations (assigned, remaining)
        return [assigned[b].pop() if assigned[b] else remaining.pop()
                for b in B]


# -------------------------
if __name__ == "__main__":
    A = [2,7,11,15]
    B = [1,10,4,11]

    solution = Solution()
    advantage_count = solution.advantageCount(A, B)
    print(f"The solution of this problem is {advantage_count}")
