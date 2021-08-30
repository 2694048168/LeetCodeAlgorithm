#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestAwesome.py
@Function: 出最长的超赞子字符串
@Link: https://leetcode-cn.com/problems/find-longest-awesome-substring/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-30
"""


class Solution:
    def longestAwesome(self, s: str) -> int:
        n = len(s)
        prefix = {0: -1}
        ans, sequence = 0, 0

        for j in range(n):
            digit = ord(s[j]) - ord("0")
            sequence ^= (1 << digit)
            if sequence in prefix:
                ans = max(ans, j - prefix[sequence])
            else:
                prefix[sequence] = j
            for k in range(10):
                if sequence ^ (1 << k) in prefix:
                    ans = max(ans, j - prefix[sequence ^ (1 << k)])

        return ans


# -----------------------------
if __name__ == "__main__":
    str = "3242415"

    solution = Solution()
    longest_some = solution.longestAwesome(str)
    print(f"The solutio of this problem is {longest_some}")
