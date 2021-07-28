#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isAnagram.py
@Function: 有效的字母异位词
@Link: https://leetcode-cn.com/problems/valid-anagram/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-28
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = [0] * 26
        for i in range(len(s)):
            # 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[ord(s[i]) - ord("a")] += 1
        # print(record)
        for i in range(len(t)):
            record[ord(t[i]) - ord("a")] -= 1
        for i in range(26):
            if record[i] != 0:
                # record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return False
        return True

# 借助 python 语言本身一些特性
class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import defaultdict

        s_dict = defaultdict(int)
        t_dict = defaultdict(int)

        for x in s:
            s_dict[x] += 1

        for x in t:
            t_dict[x] += 1

        return s_dict == t_dict


# ----------------------------------
if __name__ == "__main__":
    s = "anagram"
    t = "nagaram"

    solution = Solution()
    check_anagram = solution.isAnagram(s, t)
    print(f"The solution of this problem is : {check_anagram}")
