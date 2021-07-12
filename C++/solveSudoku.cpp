/**
 * @File    : solveSudoku.cpp
 * @Brief   : 解数独 回溯法求解 进阶的搜索方法和剪枝策略可以提高速度，如启发式搜索
 * @Link    : https://leetcode-cn.com/problems/sudoku-solver/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

// https://leetcode-cn.com/problems/sudoku-solver/solution/jie-shu-du-by-leetcode-solution/

#include <iostream>
#include <vector>
#include <cstring>

class Solution
{
private:
    int line[9];
    int column[9];
    int block[3][3];
    bool valid;
    std::vector<std::pair<int, int>> spaces;

public:
    void flip(int i, int j, int digit)
    {
        line[i] ^= (1 << digit);
        column[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }

    void dfs(std::vector<std::vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
        for (; mask && !valid; mask &= (mask - 1))
        {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }

    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        std::memset(line, 0, sizeof(line));
        std::memset(column, 0, sizeof(column));
        std::memset(block, 0, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
            }
        }

        dfs(board, 0);
    }
};

// -----------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
