/**
 * @File    : findCircleNum.cpp
 * @Brief   : 省份数量 熟悉 图 的表示方法
 * @Link    : https://leetcode-cn.com/problems/number-of-provinces/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>
#include <queue>

class Solution2
{
public:
    // 主函数
    int findCircleNum(std::vector<std::vector<int>> &friends)
    {
        int n = friends.size(), count = 0;
        std::vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(friends, i, visited);
                ++count;
            }
        }
        return count;
    }

    // 辅函数
    void dfs(std::vector<std::vector<int>> &friends, int i, std::vector<bool> &visited)
    {
        visited[i] = true;
        for (int k = 0; k < friends.size(); ++k)
        {
            if (friends[i][k] == 1 && !visited[k])
            {
                dfs(friends, k, visited);
            }
        }
    }
};

// 广度优先搜索
class Solution
{
public:
    int findCircleNum(std::vector<std::vector<int>> &isConnected)
    {
        int provinces = isConnected.size();
        std::vector<int> visited(provinces);
        int circles = 0;
        std::queue<int> Q;
        for (int i = 0; i < provinces; i++)
        {
            if (!visited[i])
            {
                Q.push(i);
                while (!Q.empty())
                {
                    int j = Q.front();
                    Q.pop();
                    visited[j] = 1;
                    for (int k = 0; k < provinces; k++)
                    {
                        if (isConnected[j][k] == 1 && !visited[k])
                        {
                            Q.push(k);
                        }
                    }
                }
                circles++;
            }
        }
        return circles;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> connected{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    // std::vector<std::vector<int>> connected{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    Solution solution;
    auto num_connnected = solution.findCircleNum(connected);
    std::cout << "The solution of this problem is : " << num_connnected << std::endl;

    return 0;
}
