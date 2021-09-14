#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reverseWords.py
@Function: 翻转单词顺序
@Link: https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-14
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()  # 删除首尾空格
        i = j = len(s) - 1
        res = []
        while i >= 0:
            while i >= 0 and s[i] != ' ':
                i -= 1  # 搜索首个空格
            res.append(s[i + 1: j + 1])  # 添加单词
            while s[i] == ' ':
                i -= 1  # 跳过单词间空格
            j = i  # j 指向下个单词的尾字符
        return ' '.join(res)  # 拼接并返回


# -----------------------------------
if __name__ == "__main__":
    str = "a good   example"

    solution = Solution()
    reverse_words = solution.reverseWords(str)
    print(f"The solution of this problem is : {reverse_words}")
