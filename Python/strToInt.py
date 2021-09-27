#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: strToInt.py
@Function: 把字符串转换成整数
@Link: https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-27
"""


class Solution2:
    def strToInt(self, str: str) -> int:
        res, i, sign, length = 0, 0, 1, len(str)
        int_max, int_min, bndry = 2 ** 31 - 1, -2 ** 31, 2 ** 31 // 10
        if not str:
            return 0         # 空字符串，提前返回
        while str[i] == ' ':
            i += 1
            if i == length:
                return 0  # 字符串全为空格，提前返回
        if str[i] == '-':
            sign = -1
        if str[i] in '+-':
            i += 1
        for c in str[i:]:
            if not '0' <= c <= '9':
                break
            if res > bndry or res == bndry and c > '7':
                return int_max if sign == 1 else int_min
            res = 10 * res + ord(c) - ord('0')
        return sign * res


class Solution:
    def strToInt(self, s: str) -> int:
        num = 0
        dic = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4,
               "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}
        minus = 0
        minsize = 2147483648
        maxsize = 2147483647
        noNum = True
        for i in range(len(s)):
            if noNum and minus == 0 and s[i] == "+":
                minus = 1
                noNum = False
            elif noNum and minus == 0 and s[i] == "-":
                minus = -1
                noNum = False
            elif "0" <= s[i] <= "9":
                tmp = dic[s[i]]
                if minus == -1:
                    if num > (minsize - tmp) // 10:
                        return -minsize
                else:
                    if num > (maxsize - tmp) // 10:
                        return maxsize
                num *= 10
                num += tmp
                if noNum:
                    noNum = False
            else:
                if noNum and s[i] == " ":
                    continue
                return -num if minus == -1 else num
        return -num if minus == -1 else num


# -------------------------
if __name__ == "__main__":
    # str_number = "4193 with words"
    str_number = "-42"

    solution = Solution()
    number = solution.strToInt(str_number)
    print(f"The solution of this problem is {number}")
