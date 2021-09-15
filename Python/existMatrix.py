#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: existMatrix.py
@Function: 矩阵中的路径
@Link: https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-15
"""


from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, k):
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] = ''
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k +
                                              1) or dfs(i, j + 1, k + 1) or dfs(i, j - 1, k + 1)
            board[i][j] = word[k]
            return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True
        return False


# -------------------------
if __name__ == "__main__":
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "ABCCED"

    solution = Solution()
    check_exist_matrix = solution.exist(board=board, word=word)
    print(f"The solution of this problem is : {check_exist_matrix}")
