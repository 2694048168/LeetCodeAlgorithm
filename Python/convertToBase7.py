#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: convertToBase7.py
@Function: 七进制数 数学问题
@Link: https://leetcode-cn.com/problems/base-7/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-18
"""


class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        ans = []
        is_negative = num < 0
        num = abs(num)
        while num > 0:
            num, remain = num // 7, num % 7
            ans.append(str(remain))

        return "-" + "".join(ans[::-1]) if is_negative else "".join(ans[::-1])


# ----------------------------------
if __name__ == "__main__":
    # n = 100
    n = -7

    solution = Solution()
    base_num = solution.convertToBase7(n)
    print(f"The solution of this problem is : {base_num}")
