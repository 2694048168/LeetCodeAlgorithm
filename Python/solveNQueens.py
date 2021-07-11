#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: solveNQueens.py
@Function: N 皇后 回溯算法 + 位运算
@Link: https://leetcode-cn.com/problems/n-queens/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""


class Solution:
    def solveNQueens(self, n):
        def generateBoard():
            board = list()
            for i in range(n):
                row[queens[i]] = "Q"
                board.append("".join(row))
                row[queens[i]] = "."
            return board

        def solve(row: int, columns: int, diagonals1: int, diagonals2: int):
            if row == n:
                board = generateBoard()
                solutions.append(board)
            else:
                availablePositions = (
                    (1 << n) - 1) & (~(columns | diagonals1 | diagonals2))
                while availablePositions:
                    position = availablePositions & (-availablePositions)
                    availablePositions = availablePositions & (
                        availablePositions - 1)
                    column = bin(position - 1).count("1")
                    queens[row] = column
                    solve(row + 1, columns | position, (diagonals1 |
                          position) << 1, (diagonals2 | position) >> 1)

        solutions = list()
        queens = [-1] * n
        row = ["."] * n
        solve(0, 0, 0, 0)
        return solutions


# -------------------------
if __name__ == "__main__":
    n = 4
    # n = 1

    solution = Solution()
    n_queens = solution.solveNQueens(n)
    print(f"The solution of this problem is : {n_queens}")
