/**
 * @File    : existMatrix.cpp
 * @Brief   : 矩阵中的路径
 * @Link    : https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-15
*/

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int m, n;
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(std::vector<std::vector<char>> &board, std::string &word, int x, int y, int k)
    {
        if (k == word.size())
            return true;
        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = board[x][y];
        board[x][y] = '*';
        for (int i = 0; i < 4; ++i)
        {
            int mx = x + dx[i], my = y + dy[i];
            if (mx >= 0 && mx < m && my >= 0 && my < n && board[mx][my] == word[k])
            {
                if (dfs(board, word, mx, my, k + 1))
                    return true;
            }
        }
        board[x][y] = t;
        return false;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<char>> board{{'a', 'b'}, {'c', 'd'}};
    // std::string word = "abcd";
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";

    Solution solution;
    bool check_exist_matrix = solution.exist(board, word);
    std::cout << "The solution of this problem is " << std::boolalpha << check_exist_matrix << std::endl;

    return 0;
}
