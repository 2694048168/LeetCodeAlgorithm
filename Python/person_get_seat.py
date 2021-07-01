#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: person_get_seat.py
@Function: 飞机座位分配概率，概率分析以及化简(考虑时间复杂度 T(n) )
@Link: https://leetcode-cn.com/problems/airplane-seat-assignment-probability/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-01
"""

class Solution:
    def nthPersonGetsNthSeat(self, n):
        return 1.0 if n == 1 else 0.5


if __name__ == "__main__":
    num_person = 723

    solution = Solution()
    probability = solution.nthPersonGetsNthSeat(num_person)

    print(f"The Probability of the n-th passenger sitting in his seat: {probability}")