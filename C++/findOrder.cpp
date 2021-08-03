/**
 * @File    : findOrder.cpp
 * @Brief   : 课程表 II
 * @Link    : https://leetcode-cn.com/problems/course-schedule-ii/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
        std::vector<int> indegree(numCourses, 0), res;
        for (const auto &prerequisite : prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        std::queue<int> q;
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (!indegree[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            res.push_back(u);
            q.pop();
            for (auto v : graph[u])
            {
                --indegree[v];
                if (!indegree[v])
                {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (indegree[i])
            {
                return std::vector<int>();
            }
        }
        return res;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -------------------------------
int main(int argc, char **argv)
{
    // int numCourses = 2;
    // std::vector<std::vector<int>> prerequisites{{1, 0}};

    int numCourses = 4;
    std::vector<std::vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution solution;
    auto find_order_vec = solution.findOrder(numCourses, prerequisites);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(find_order_vec);

    return 0;
}
