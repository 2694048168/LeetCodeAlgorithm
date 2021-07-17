/**
 * @File    : beautifulArray.cpp
 * @Brief   : 漂亮数组 分治算法策略 & 动态规划策略
 * @Link    : https://leetcode-cn.com/problems/beautiful-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-17
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::unordered_map<int, std::vector<int>> mp;
    std::vector<int> beautifulArray(int N)
    {
        return f(N);
    }
    std::vector<int> f(int N)
    {
        std::vector<int> ans(N, 0);
        int t = 0;
        if (mp.find(N) != mp.end())
        {
            return mp[N];
        }
        if (N != 1)
        {
            for (auto x : f((N + 1) / 2))
            {
                ans[t++] = 2 * x - 1;
            }
            for (auto x : f(N / 2))
            {
                ans[t++] = 2 * x;
            }
        }
        else
        {
            ans[0] = 1;
        }
        mp[N] = ans;
        return ans;
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

// --------------------------------
int main(int argc, char **argv)
{
    // int n = 4;
    int n = 5;

    Solution solution;
    auto beautiful_array = solution.beautifulArray(n);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(beautiful_array);

    return 0;
}
