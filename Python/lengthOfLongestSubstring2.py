#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lengthOfLongestSubstring2.py
@Function: 最长不含重复字符的子字符串
@Link: https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-12
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic, res, i = {}, 0, -1
        for j in range(len(s)):
            if s[j] in dic:
                i = max(dic[s[j]], i)  # 更新左指针 i
            dic[s[j]] = j  # 哈希表记录
            res = max(res, j - i)  # 更新结果
        return res


# ----------------------------------
if __name__ == "__main__":
    str = "abcabcbb"

    solution = Solution()
    length_longest_substring = solution.lengthOfLongestSubstring(str)
    print(f"The solution of this problem is : {length_longest_substring}")
