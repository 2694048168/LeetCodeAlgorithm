#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: firstUniqChar2.py
@Function: 第一个只出现一次的字符
@Link: https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-06
"""


from typing import List
import collections


class Solution:
    def firstUniqChar(self, s: str) -> str:
        position = dict()
        q = collections.deque()
        n = len(s)
        for i, ch in enumerate(s):
            if ch not in position:
                position[ch] = i
                q.append((s[i], i))
            else:
                position[ch] = -1
                while q and position[q[0][0]] == -1:
                    q.popleft()
        return ' ' if not q else q[0][0]


# --------------------------
if __name__ == "__main__":
    str = "abaccdeff"

    solution = Solution()
    first_uniq_char = solution.firstUniqChar(str)
    print(f"The solution of this proble is {first_uniq_char}")
