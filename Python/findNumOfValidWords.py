#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findNumOfValidWords.py
@Function: 猜字谜
@Link: https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-30
"""


from typing import List
import collections


class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        frequency = collections.Counter()

        for word in words:
            mask = 0
            for ch in word:
                mask |= (1 << (ord(ch) - ord("a")))
            if str(bin(mask)).count("1") <= 7:
                frequency[mask] += 1

        ans = list()
        for puzzle in puzzles:
            total = 0

            # 枚举子集方法一
            # for choose in range(1 << 6):
            #     mask = 0
            #     for i in range(6):
            #         if choose & (1 << i):
            #             mask |= (1 << (ord(puzzle[i + 1]) - ord("a")))
            #     mask |= (1 << (ord(puzzle[0]) - ord("a")))
            #     if mask in frequency:
            #         total += frequency[mask]

            # 枚举子集方法二
            mask = 0
            for i in range(1, 7):
                mask |= (1 << (ord(puzzle[i]) - ord("a")))

            subset = mask
            while subset:
                s = subset | (1 << (ord(puzzle[0]) - ord("a")))
                if s in frequency:
                    total += frequency[s]
                subset = (subset - 1) & mask

            # 在枚举子集的过程中，要么会漏掉全集 mask，要么会漏掉空集
            # 这里会漏掉空集，因此需要额外判断空集
            if (1 << (ord(puzzle[0]) - ord("a"))) in frequency:
                total += frequency[1 << (ord(puzzle[0]) - ord("a"))]

            ans.append(total)

        return ans


# -----------------------------
if __name__ == "__main__":
    words = ["aaaa", "asas", "able", "ability", "actt", "actor", "access"]
    puzzles = ["aboveyz", "abrodyz", "abslute",
               "absoryz", "actresz", "gaswxyz"]

    solution = Solution()
    find_number_valid_words = solution.findNumOfValidWords(words, puzzles)
    print(f"The solutio of this problem is {find_number_valid_words}")
