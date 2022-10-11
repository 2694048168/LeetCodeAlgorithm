#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: almost_equal.py
@Funciton Description: 仅执行一次字符串交换能否使两个字符串相等
@Cite: https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/10/11 10:51:58
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''


class Solution:
    def areAlmostEqual(self, s1, s2):
        i = j = -1
        for idx, (x, y) in enumerate(zip(s1, s2)):
            if x != y:
                if i < 0:
                    i = idx
                elif j < 0:
                    j = idx
                else:
                    return False
        return i < 0 or j >= 0 and s1[i] == s2[j] and s1[j] == s2[i]


# --------------------------
if __name__ == "__main__":
    s1, s2 = "bank", "kanb" #/* True */
    # s1, s2 = "yhy", "hyc" #/* False */
    # s1, s2 = "abcd", "dcba" #/* False */
    # s1, s2 = "attack", "defend" #/* False */
    # s1, s2 = "bank", "bank" #/* True */

    solution = Solution()
    equal_str = solution.areAlmostEqual(s1, s2)
    print(f"this two string is equal: {equal_str}")
