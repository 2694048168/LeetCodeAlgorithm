#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: wordBreak.py
@Function: 单词拆分 动态规划
@Link: https://leetcode-cn.com/problems/word-break/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""

from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False]*(n+1)
        dp[0] = True
        for i in range(n):
            for j in range(i+1, n+1):
                if(dp[i] and (s[i:j] in wordDict)):
                    dp[j] = True
        return dp[-1]


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        import functools

        @functools.lru_cache(None)
        def back_track(s):
            if(not s):
                return True
            res = False
            for i in range(1, len(s)+1):
                if(s[:i] in wordDict):
                    res = back_track(s[i:]) or res
            return res
        return back_track(s)


# ------------------------------
if __name__ == "__main__":
    # str = "leetcode"
    # word_dict = ["leet", "code"]

    str = "catsandog"
    word_dict = ["cats", "dog", "sand", "and", "cat"]

    solution = Solution()
    check = solution.wordBreak(str, word_dict)
    print(f"The solution of this problem is {check}")
