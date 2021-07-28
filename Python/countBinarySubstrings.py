#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: countBinarySubstrings.py
@Function: 计数二进制子串
@Link: https://leetcode-cn.com/problems/count-binary-substrings/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-28
"""


class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s) - 1):
            if int(s[i]) ^ int(s[i + 1]) == 1:
                index = 0
                while i - index >= 0 and i + 1 + index <= len(s) - 1:
                    if s[i - index] == s[i] and s[i + 1] == s[i + 1 + index]:
                        count += 1
                        index += 1
                    else:
                        break
        return count


# ----------------------------------
if __name__ == "__main__":
    str = "00110011"

    solution = Solution()
    num_binary_substring = solution.countBinarySubstrings(str)
    print(f"The solution of this problem is : {num_binary_substring}")
