#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findLongestWord.py
@Function: 通过删除字母匹配到字典里最长单词 Ⅱ 双指针策略
@Link: https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-08
"""

class Solution:
    def findLongestWord(self, string, dictionary):
        ## 用好 python 内置函数 sort()、find(),比双指针效率更高
        ## 可以用元组表示多关键字排序，第一关键字是长度降序，第二关键字是字符串本身字典序
        dictionary.sort(key = lambda x: (-len(x), x))

        for word in dictionary:
            index = 0
            for ch in word:
                index = string.find(ch, index) + 1  # find 输出 -1:False
                if not index:
                    break
            else:       # 这里用 else 语句保证 break 之后不会执行，正常循环结束会执行
                return word
        return ""


# -------------------------
if __name__ == "__main__":
    s = "abpcplea"
    # dictionary = ["ale", "apple", "monkey", "plea"]
    dictionary = ["a", "b", "c"]

    solution = Solution()
    longest_word = solution.findLongestWord(string=s, dictionary=dictionary)
    print(f"The solution of this problem is : {longest_word}")