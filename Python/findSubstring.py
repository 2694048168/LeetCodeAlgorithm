#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findSubstring.py
@Function: 串联所有单词的子串
@Link: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-17
"""


from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        from collections import Counter
        if not s or not words:
            return []
        one_word = len(words[0])
        word_num = len(words)
        n = len(s)
        if n < one_word:
            return []
        words = Counter(words)
        res = []
        for i in range(0, one_word):
            cur_cnt = 0
            left = i
            right = i
            cur_Counter = Counter()
            while right + one_word <= n:
                w = s[right:right + one_word]
                right += one_word
                if w not in words:
                    left = right
                    cur_Counter.clear()
                    cur_cnt = 0
                else:
                    cur_Counter[w] += 1
                    cur_cnt += 1
                    while cur_Counter[w] > words[w]:
                        left_w = s[left:left+one_word]
                        left += one_word
                        cur_Counter[left_w] -= 1
                        cur_cnt -= 1
                    if cur_cnt == word_num:
                        res.append(left)
        return res


# -------------------------
if __name__ == "__main__":
    # s = "barfoothefoobarman"
    # words = ["foo", "bar"]

    s = "barfoofoobarthefoobarman"
    words = ["bar", "foo", "the"]

    solution = Solution()
    find_substring = solution.findSubstring(s, words)
    print(f"The solution of this problem is {find_substring}")
