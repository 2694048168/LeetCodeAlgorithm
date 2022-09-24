#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: sub_sequence.py
@Function: 判断子序列
@Link: https://leetcode.cn/problems/is-subsequence/
@Python Version: 3.9.7
@Author: Wei Li (weili_yzzcq@163.com)
@Date: 2022-09-24
"""


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ptr_s, ptr_t = 0, 0 # 双指针思想
        while (ptr_s < len(s)) and (ptr_t < len(t)):
            if s[ptr_s] == t[ptr_t]: # 贪心思想
                ptr_s +=1
            ptr_t += 1

        return ptr_s == len(s) # s 是否匹配完全


# ----------------------------------
if __name__ == "__main__":
    # str_1 = "axc"
    # str_2 = "ahbgdc"
    str_1 = "abc"
    str_2 = "ahbgdc"

    solution = Solution()
    sub_sequence = solution.isSubsequence(str_1, str_2)
    print(f"The solution of this problem is : {sub_sequence}")
