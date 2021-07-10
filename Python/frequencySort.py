#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: frequencySort.py
@Function: 根据字符出现频率排序 给定一个字符串，请将字符串里的字符按照出现的频率降序排列
@Link: https: // leetcode-cn.com/problems/sort-characters-by-frequency/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-10
"""

from collections import Counter


class Solution:
    def frequencySort(self, str):
        # python 使用一些内置的模块功能，效率更高一点
        c = Counter(str)
        return "".join(v for v in sorted(c.keys(), key=lambda x: -c[x]) for i in range(c[v]))


# --------------------------
if __name__ == "__main__":
    # str = "tree"
    str = "Aabb"

    solution = Solution()
    fre_str = solution.frequencySort(str)
    print(f"The solution of this problem is : {fre_str}")
