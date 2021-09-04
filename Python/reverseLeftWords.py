#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reverseLeftWords.py
@Function: 左旋转字符串
@Link: https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-04
"""


# # 方法一：可以使用切片方法
# class Solution:
#     def reverseLeftWords(self, s: str, n: int) -> str:
#         return s[n:] + s[0:n]

# 方法二：也可以使用上文描述的方法，有些面试中不允许使用切片，那就使用上文作者提到的方法
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s = list(s)
        s[0:n] = list(reversed(s[0:n]))
        s[n:] = list(reversed(s[n:]))
        s.reverse()

        return "".join(s)


# ----------------------------------
if __name__ == "__main__":
    str = "lrloseumgh"
    k = 6

    solution = Solution()
    reverse_left_words = solution.reverseLeftWords(str, k)
    print(f"The solution of this problem is {reverse_left_words}")
