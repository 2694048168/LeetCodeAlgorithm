/**
 * @File    : solve.cpp
 * @Brief   : 被围绕的区域
 * @Link    : https://leetcode-cn.com/problems/surrounded-regions/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

#include <iostream>
#include <vector>
#include <queue>
// #include <utility>

// 方法一：深度优先搜索
class Solution
{
public:
    int n, m;

    void dfs(std::vector<std::vector<char>> &board, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O')
        {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(std::vector<std::vector<char>> &board)
    {
        n = board.size();
        if (n == 0)
        {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++)
        {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// 方法二：广度优先搜索
class Solution2
{
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    void solve(std::vector<std::vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
        {
            return;
        }
        int m = board[0].size();
        std::queue<std::pair<int, int>> que;
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                que.emplace(i, 0);
            }
            if (board[i][m - 1] == 'O')
            {
                que.emplace(i, m - 1);
            }
        }
        for (int i = 1; i < m - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                que.emplace(0, i);
            }
            if (board[n - 1][i] == 'O')
            {
                que.emplace(n - 1, i);
            }
        }
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            board[x][y] = 'A';
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i], my = y + dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O')
                {
                    continue;
                }
                que.emplace(mx, my);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
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

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    std::cout << "The board before processing is that : " << std::endl;
    DisplayElement(board);
    Solution solution;
    solution.solve(board);
    std::cout << "The board after processing is that : " << std::endl;
    DisplayElement(board);

    return 0;
}
