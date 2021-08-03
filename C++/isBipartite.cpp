/**
 * @File    : isBipartite.cpp
 * @Brief   : 判断二分图
 * @Link    : https://leetcode-cn.com/problems/is-graph-bipartite/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    bool isBipartite(std::vector<std::vector<int>> &graph)
    {
        int n = graph.size();
        if (n == 0)
        {
            return true;
        }
        std::vector<int> color(n, 0);
        std::queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!color[i])
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (const int &j : graph[node])
                {
                    if (color[j] == 0)
                    {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    }
                    else if (color[node] == color[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    std::vector<std::vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    Solution solution;
    bool check_bipartite = solution.isBipartite(graph);
    std::cout << "The solution of this problem is " << std::boolalpha << check_bipartite << std::endl;

    return 0;
}
