/**
 * @File    : movingCount.cpp
 * @Brief   : 机器人的运动范围
 * @Link    : https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-15
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

class Solution
{
    // 计算 x 的数位之和
    int get(int x)
    {
        int res = 0;
        for (; x; x /= 10)
        {
            res += x % 10;
        }
        return res;
    }

public:
    int movingCount(int m, int n, int k)
    {
        if (!k)
            return 1;
        std::queue<std::pair<int, int>> Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        Q.push(std::make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty())
        {
            // auto [x, y] = Q.front(); // std==C++17
            auto x = Q.front().first; 
            auto y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 2; ++i)
            {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k)
                    continue;
                Q.push(std::make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    int m = 2, n = 3, k = 1;

    Solution solution; 
    auto moving_count = solution.movingCount(m, n, k);
    std::cout << "The solution of this problem is " << moving_count << std::endl;

    return 0;
}
