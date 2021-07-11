/**
 * @File    : exist.cpp
 * @Brief   : 单词搜索 回溯算法
 * @Link    : https://leetcode-cn.com/problems/word-search/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    // 主函数
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        if (board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }
    // 辅函数
    void backtracking(int i, int j, std::vector<std::vector<char>> &board, std::string &word, bool &find, std::vector<std::vector<bool>> &visited, int pos)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return;
        }
        if (visited[i][j] || find || board[i][j] != word[pos])
        {
            return;
        }
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        visited[i][j] = true; // 修改当前节点状态
        // 递归子节点
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false; // 回改当前节点状态
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // std::string word{"ABCCED"};
    std::string word{"ABCB"};

    Solution solution;
    bool check = solution.exist(board, word);
    std::cout << "The solution of this problem is : " << std::boolalpha << check << std::endl;

    return 0;
}
