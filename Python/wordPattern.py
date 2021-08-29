#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: wordPattern.py
@Function: 单词规律
@Link: https://leetcode-cn.com/problems/word-pattern/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-29
"""


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        word2ch = dict()
        ch2word = dict()
        words = s.split()
        if len(pattern) != len(words):
            return False

        for ch, word in zip(pattern, words):
            if (word in word2ch and word2ch[word] != ch) or (ch in ch2word and ch2word[ch] != word):
                return False
            word2ch[word] = ch
            ch2word[ch] = word

        return True


# ------------------------------
if __name__ == "__main__":
    pattern = "abba"
    # str = "dog cat cat dog"
    str = "dog cat cat fish"

    solution = Solution()
    check_word_pattern = solution.wordPattern(pattern, str)
    print(f"The solution of this problem is {check_word_pattern}")
