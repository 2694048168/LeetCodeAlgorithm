#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isNumberStr.py
@Function: 表示数值的字符串
@Link: https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-27
"""


from enum import Enum


class Solution2:
    def isNumber(self, s: str) -> bool:
        State = Enum("State", [
            "STATE_INITIAL",
            "STATE_INT_SIGN",
            "STATE_INTEGER",
            "STATE_POINT",
            "STATE_POINT_WITHOUT_INT",
            "STATE_FRACTION",
            "STATE_EXP",
            "STATE_EXP_SIGN",
            "STATE_EXP_NUMBER",
            "STATE_END"
        ])
        Chartype = Enum("Chartype", [
            "CHAR_NUMBER",
            "CHAR_EXP",
            "CHAR_POINT",
            "CHAR_SIGN",
            "CHAR_SPACE",
            "CHAR_ILLEGAL"
        ])

        def toChartype(ch: str) -> Chartype:
            if ch.isdigit():
                return Chartype.CHAR_NUMBER
            elif ch.lower() == "e":
                return Chartype.CHAR_EXP
            elif ch == ".":
                return Chartype.CHAR_POINT
            elif ch == "+" or ch == "-":
                return Chartype.CHAR_SIGN
            elif ch == " ":
                return Chartype.CHAR_SPACE
            else:
                return Chartype.CHAR_ILLEGAL

        transfer = {
            State.STATE_INITIAL: {
                Chartype.CHAR_SPACE: State.STATE_INITIAL,
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_POINT: State.STATE_POINT_WITHOUT_INT,
                Chartype.CHAR_SIGN: State.STATE_INT_SIGN
            },
            State.STATE_INT_SIGN: {
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_POINT: State.STATE_POINT_WITHOUT_INT
            },
            State.STATE_INTEGER: {
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_POINT: State.STATE_POINT,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_POINT: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_POINT_WITHOUT_INT: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION
            },
            State.STATE_FRACTION: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_EXP: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER,
                Chartype.CHAR_SIGN: State.STATE_EXP_SIGN
            },
            State.STATE_EXP_SIGN: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER
            },
            State.STATE_EXP_NUMBER: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_END: {
                Chartype.CHAR_SPACE: State.STATE_END
            },
        }

        st = State.STATE_INITIAL
        for ch in s:
            typ = toChartype(ch)
            if typ not in transfer[st]:
                return False
            st = transfer[st][typ]

        return st in [State.STATE_INTEGER, State.STATE_POINT, State.STATE_FRACTION, State.STATE_EXP_NUMBER, State.STATE_END]


class Solution:
    def isNumber(self, s: str) -> bool:
        states = [
            {' ': 0, 's': 1, 'd': 2, '.': 4},  # 0. start with 'blank'
            {'d': 2, '.': 4},                # 1. 'sign' before 'e'
            {'d': 2, '.': 3, 'e': 5, ' ': 8},  # 2. 'digit' before 'dot'
            {'d': 3, 'e': 5, ' ': 8},         # 3. 'digit' after 'dot'
            # 4. 'digit' after 'dot' (‘blank’ before 'dot')
            {'d': 3},
            {'s': 6, 'd': 7},                 # 5. 'e'
            {'d': 7},                         # 6. 'sign' after 'e'
            {'d': 7, ' ': 8},                 # 7. 'digit' after 'e'
            {' ': 8}                          # 8. end with 'blank'
        ]
        p = 0
        for c in s:
            if '0' <= c <= '9':
                t = 'd'  # digit
            elif c in "+-":
                t = 's'     # sign
            elif c in "eE":
                t = 'e'     # e or E
            elif c in ". ":
                t = c       # dot, blank
            else:
                t = '?'               # unknown
            if t not in states[p]:
                return False
            p = states[p][t]
        return p in (2, 3, 7, 8)


# -------------------------
if __name__ == "__main__":
    str = "    .1  "

    solution = Solution()
    is_valid_number = solution.isNumber(str)
    print(f"The solution of this problem is {is_valid_number}")
