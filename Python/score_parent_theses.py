#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: score_parent_theses.py
@Funciton Description: 括号的分数
@Cite LeetCode: https://leetcode.cn/problems/score-of-parentheses/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/10/09 18:06:08
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''

class Solution():
    def scoreOfParentheses(self, str):
        score_ans = 0
        depth_cur = 0
        for i, char in enumerate(str):
            depth_cur += 1 if char == '(' else -1
            if char == ")" and str[i - 1] == '(':
                score_ans += pow(2, depth_cur)

        return score_ans


# -------------------------
if __name__ == "__main__":
    # str = "()" # score=1
    # str = "()()" # score=2
    # str = "(())" # score=2
    str = "(()(()))" # score=6

    solution = Solution()
    score = solution.scoreOfParentheses(str)
    print(f"the score of parent string: {score}")
