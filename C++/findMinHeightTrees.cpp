/**
 * @File    : findMinHeightTrees.cpp
 * @Brief   : 最小高度树
 * @Link    : https://leetcode-cn.com/problems/minimum-height-trees/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

#include <iostream>
#include <vector>
#include <queue>

// 拓扑排序
class Solution
{
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        // 根据边表edges 创建图(邻接数组)
        std::vector<std::vector<short>> adjList(n);
        std::vector<short> degree(n, 0);
        for (short i = 0; i < edges.size(); ++i)
        {
            short v1 = edges[i][0];
            short v2 = edges[i][1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);

            ++degree[v1];
            ++degree[v2];
        }

        // BFS拓扑排序
        // 初始化
        std::queue<short> Q;
        for (short i = 0; i < n; ++i)
        {
            if (degree[i] == 1)
            {
                Q.push(i);
            }
        }

        while (Q.size())
        {
            short size = Q.size();
            if (size == n)
                break; // 终止条件
            n -= size;

            while (size--)
            {
                short cur = Q.front();
                Q.pop();

                // 访问邻接点，找出正确的下一个adj
                short adj;
                for (short i = 0; i < adjList[cur].size(); ++i)
                {
                    adj = adjList[cur][i];
                    if (degree[adj] > 1)
                        break; // 度=1的是已经被访问过的
                }
                --degree[adj];

                if (degree[adj] == 1)
                {
                    Q.push(adj);
                }
            }
        }

        std::vector<int> ans;
        while (Q.size())
        {
            ans.push_back(Q.front());
            Q.pop();
        }

        return ans;
    }
};

// ------------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
