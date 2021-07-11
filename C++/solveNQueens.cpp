/**
 * @File    : solveNQueens.cpp
 * @Brief   : N 皇后
 * @Link    : https://leetcode-cn.com/problems/n-queens/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    // 主函数
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> ans;
        if (n == 0)
        {
            return ans;
        }
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<bool> column(n, false), ldiag(2 * n - 1, false), rdiag(2 * n - 1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }
    // 辅函数
    void backtracking(std::vector<std::vector<std::string>> &ans, std::vector<std::string> &board, std::vector<bool> &column, std::vector<bool> &ldiag, std::vector<bool> &rdiag, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i + 1])
            {
                continue;
            }
            // 修改当前节点状态
            board[row][i] = 'Q';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = true;
            // 递归子节点
            backtracking(ans, board, column, ldiag, rdiag, row + 1, n);
            // 回改当前节点状态
            board[row][i] = '.';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = false;
        }
    }
};


template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        for (auto value = element->begin(); value != element->end(); ++value)
        {
            std::cout << *value << " ";
        }
    }
    std::cout << std::endl;
}


// -----------------------------
int main(int argc, char **argv)
{
    // int n = 4;
    int n = 1;

    Solution solution;
    auto N_Queens = solution.solveNQueens(n);
    std::cout << "The solution of this problem is :" << std::endl;
    DisplayElement(N_Queens);

    return 0;
}
