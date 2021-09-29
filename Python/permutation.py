#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: permutation.py
@Function: 字符串的排列
@Link: https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-29
"""


from typing import List

class Solution:
    def permutation(self, s: str) -> List[str]:
        c, res = list(s), []
        def dfs(x):
            if x == len(c) - 1:
                res.append(''.join(c))   # 添加排列方案
                return
            dic = set()
            for i in range(x, len(c)):
                if c[i] in dic: continue # 重复，因此剪枝
                dic.add(c[i])
                c[i], c[x] = c[x], c[i]  # 交换，将 c[i] 固定在第 x 位
                dfs(x + 1)               # 开启固定第 x + 1 位字符
                c[i], c[x] = c[x], c[i]  # 恢复交换
        dfs(0)
        return res


# -------------------------
if __name__ == "__main__":
    str = "abc"

    solution = Solution()
    str_permutation = solution.permutation(str)
    print(f"The solution of this problem is \n{str_permutation}")
