/**
 * @File    : countPairs.cpp
 * @Brief   : 统计点对的数目
 * @Link    : https://leetcode-cn.com/problems/count-pairs-of-nodes/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<int> countPairs(int n, std::vector<std::vector<int>> &edges, std::vector<int> &queries)
    {
        std::vector<int> deg(n + 1, 0);

        int nEdges = edges.size();
        std::unordered_map<int, int> overlap;
        std::vector<std::vector<int>> distinctEdges; // 去除重边后的边数组，这样处理每个 query 时能少遍历几条边
        auto encode = [n](int a, int b) -> int
        { return std::max(a, b) * (n + 1) + std::min(a, b); };
        for (int i = 0; i < nEdges; i++)
        {
            int p = edges[i][0], q = edges[i][1];
            deg[p]++;
            deg[q]++;
            int idx = encode(p, q);
            if (overlap.find(idx) == overlap.end())
            {
                distinctEdges.push_back({p, q});
            }
            overlap[idx]++;
        }

        std::vector<int> sortedDeg(deg.begin() + 1, deg.end());
        std::sort(sortedDeg.begin(), sortedDeg.end());

        int nQueries = queries.size();
        std::vector<int> ret(nQueries);
        for (int i = 0; i < nQueries; i++)
        {
            int l = 0, r = n - 1;
            int cnt = 0;
            while (l < n)
            {
                while (r > l && sortedDeg[l] + sortedDeg[r] > queries[i])
                {
                    r--;
                }
                cnt += (n - std::max(l, r) - 1);
                l++;
            }

            for (int j = 0; j < distinctEdges.size(); j++)
            {
                int p = distinctEdges[j][0], q = distinctEdges[j][1];
                int idx = encode(p, q);
                if (deg[p] + deg[q] > queries[i] && deg[p] + deg[q] - overlap[idx] <= queries[i])
                {
                    cnt--;
                }
            }
            ret[i] = cnt;
        }
        return ret;
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
// ----------------------------
int main(int argc, char **argv)
{
    int n = 4;
    std::vector<std::vector<int>> edges{{1, 2}, {2, 4}, {1, 3}, {2, 3}, {2, 1}};
    std::vector<int> queries{2, 3};

    Solution solution;
    auto count_pairs = solution.countPairs(n, edges, queries);
    DisplayElement(count_pairs);

    return 0;
}
