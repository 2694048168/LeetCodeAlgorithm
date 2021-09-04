#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: replaceSpace.py
@Function: 替换空格
@Link: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-04
"""


from typing import List


class Solution:
    def replaceSpace(self, s: str) -> str:
        res = []
        for c in s:
            if c == ' ':
                res.append("%20")
            else:
                res.append(c)
        return "".join(res)


# ----------------------------------
if __name__ == "__main__":
    str = "We are happy."
    
    solution = Solution()
    replace_space_str = solution.replaceSpace(str)
    print(f"The solution of this problem is {replace_space_str}")
