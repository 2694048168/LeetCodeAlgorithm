#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: merge.py
@Function: 最小覆盖子串 滑动窗口策略 & 双指针策略
@Link: https://leetcode-cn.com/problems/minimum-window-substring/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-07
"""

import collections


# 思路一：滑动窗口 + 哈希表
class Solution:
    def minWindow(self, s, t):
        n, m = len(s), len(t)
        if n < m:
            return ""

        need = collections.defaultdict(int)
        for c in t:
            need[c] += 1
        need_cnt = m
        res = [0, n]

        left = 0
        for right, c in enumerate(s):
            if need [c] > 0:
                need_cnt -= 1
            need[c] -= 1
            if need_cnt == 0:
                while True:
                    if need[s[left]] == 0:
                        break
                    need[s[left]] += 1
                    left += 1
                if right - left < res[1] - res[0]:
                    res = [left, right]
        return s[res[0]: res[1] + 1] if res != [0, n] else ""


# --------------------------
if __name__ == "__main__":
    s, t = "ADOBECODEBANC", "ABC"

    solution = Solution()
    min_str = solution.minWindow(s, t)
    print(f"The solution of this problem is : {min_str}")