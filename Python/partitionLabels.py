#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: partitionLabels.py
@Function: 划分字母区间 贪心策略
@Link: https://leetcode-cn.com/problems/partition-labels/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-05
"""

# -------------------------
class Solution:
    def partitionLabels(self, str):
        last = [0] * 26
        for i, ch in enumerate(str):
            last[ord(ch) - ord("a")] = i

        partition = list()
        start = end = 0
        for i, ch in enumerate(str):
            end = max(end, last[ord(ch) - ord("a")])
            if i == end:
                partition.append(end - start + 1)
                start = end + 1

        return partition


# -------------------------
if __name__ == "__main__":
    str = "ababcbacadefegdehijhklij"

    solution = Solution()
    list_partition = solution.partitionLabels(str)
    print(f"The solution of this problem is : {list_partition}")