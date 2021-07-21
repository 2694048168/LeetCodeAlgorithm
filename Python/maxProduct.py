#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProduct.py
@Function: 最大单词长度乘积
@Link: https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""


from collections import defaultdict
from typing import List


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        hashmap = defaultdict(int)
        def bit_number(ch): return ord(ch) - ord('a')

        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))

        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod


# -------------------------
if __name__ == "__main__":
    words = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]

    solution = Solution()
    max_product = solution.maxProduct(words)
    print(f"The solution of this problem is {max_product}")
