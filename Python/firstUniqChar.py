#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: firstUniqChar.py
@Function: 字符串中的第一个唯一字符
@Link: https://leetcode-cn.com/problems/first-unique-character-in-a-string/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-29
"""


class Solution:
    def firstUniqChar(self, s: str) -> int:
        position = dict()
        n = len(s)
        for i, ch in enumerate(s):
            if ch in position:
                position[ch] = -1
            else:
                position[ch] = i
        first = n
        for pos in position.values():
            if pos != -1 and pos < first:
                first = pos
        if first == n:
            first = -1
        return first


# ------------------------------
if __name__ == "__main__":
    # str = "leetcode"
    str = "loveleetcode"

    solution = Solution()
    first_uniq_char = solution.firstUniqChar(str)
    print(f"The solution of this problem is {first_uniq_char}")
