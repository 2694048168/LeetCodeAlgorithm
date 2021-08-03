/**
 * @File    : reachableNodes.cpp
 * @Brief   : 细分图中的可到达结点
 * @Link    : https://leetcode-cn.com/problems/reachable-nodes-in-subdivided-graph/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>

#define pii std::pair<int, int>

class Solution
{
public:
    int reachableNodes(std::vector<std::vector<int>> &edges, int M, int N)
    {
        std::vector<std::vector<pii>> graph(N);
        for (std::vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        std::map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < N; ++i)
            dist[i] = M + 1;

        std::map<pii, int> used;
        int ans = 0;

        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            pii top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node])
                continue;
            dist[node] = d;

            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            for (auto pair : graph[node])
            {
                // M - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = std::min(weight, M - d);

                // d2 is the total distance to reach 'nei' (nei***or) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < std::min(dist[nei], M + 1))
                {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }

        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        for (std::vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += std::min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> edges{{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    int M = 6, N = 3;

    Solution solution;
    auto reachable_nodes = solution.reachableNodes(edges, M, N);
    std::cout << "The solution of this problem is " << reachable_nodes << std::endl;

    return 0;
}
