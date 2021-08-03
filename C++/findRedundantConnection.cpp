/**
 * @File    : findRedundantConnection.cpp
 * @Brief   : 冗余连接
 * @Link    : https://leetcode-cn.com/problems/redundant-connection/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <vector>
#include <numeric>

class UF
{
    std::vector<int> id, size;

public:
    UF(int n) : id(n), size(n, 1)
    {
        std::iota(id.begin(), id.end(), 0); // iota函数可以把数组初始化为0到n-1
    }
    int find(int p)
    {
        while (p != id[p])
        {
            id[p] = id[id[p]]; // 路径压缩， 使得下次查找更快
            p = id[p];
        }
        return p;
    }
    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i != j)
        {
            // 按秩合并： 每次合并都把深度较小的集合合并在深度较大的集合下面
            if (size[i] < size[j])
            {
                id[i] = j;
                size[j] += size[i];
            }
            else
            {
                id[j] = i;
                size[i] += size[j];
            }
        }
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};

class Solution
{
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v))
            {
                return e;
            }
            uf.connect(u, v);
        }
        return std::vector<int>{-1, -1};
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
    std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};

    Solution solution;
    auto find_redundant_connection = solution.findRedundantConnection(edges);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(find_redundant_connection);

    return 0;
}
