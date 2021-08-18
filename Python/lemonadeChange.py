#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lemonadeChange.py
@Function: 柠檬水找零
@Link: https://leetcode-cn.com/problems/lemonade-change/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-18
"""


from collections import defaultdict


class Solution:
    def lemonadeChange(self, bills):
        dic = defaultdict(int)
        for i in bills:
            dic[i] += 1
            diff = i - 5
            while diff:
                if diff >= 10 and dic[10]:
                    dic[10] -= 1
                    diff -= 10
                elif diff >= 5 and dic[5]:
                    dic[5] -= 1
                    diff -= 5
                else:
                    return False
        return True


# ----------------------------------
if __name__ == "__main__":
    # bills = [5, 5, 5, 10, 20]
    bills = [5, 5, 10, 10, 20]

    solution = Solution()
    check_change = solution.lemonadeChange(bills)
    print(f"The solution of this problem is {check_change}")
