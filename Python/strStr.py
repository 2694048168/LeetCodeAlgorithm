#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: strStr.py
@Function: 实现 strStr()
@Link: https://leetcode-cn.com/problems/implement-strstr/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-28
"""

# Knuth-Morris-Pratt（KMP）算法，可以在 big-O(m + n) 时间利用动态规划完成匹配
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        a = len(needle)
        b = len(haystack)
        if a == 0:
            return 0
        next = self.getnext(a, needle)
        p = -1
        for j in range(b):
            while p >= 0 and needle[p+1] != haystack[j]:
                p = next[p]
            if needle[p+1] == haystack[j]:
                p += 1
            if p == a-1:
                return j-a+1
        return -1

    def getnext(self, a, needle):
        next = ['' for i in range(a)]
        k = -1
        next[0] = k
        for i in range(1, len(needle)):
            while (k > -1 and needle[k+1] != needle[i]):
                k = next[k]
            if needle[k+1] == needle[i]:
                k += 1
            next[i] = k
        return next


# ----------------------------------
if __name__ == "__main__":
    haystack = "aaaaa"
    needle = "bba"

    solution = Solution()
    str2str = solution.strStr(haystack, needle)
    print(f"The solution of this problem is : {str2str}")
