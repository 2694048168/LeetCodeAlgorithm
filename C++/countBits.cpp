/**
 * @File    : countBits.CPP
 * @Brief   : 比特位计数
 * @Link    : https://leetcode-cn.com/problems/counting-bits/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int num)
    {
        std::vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
        // 等价于dp[i] = dp[i&(i-1)] + 1;
        return dp;
    }
};


template <typename T>
void DisplayElement(const T& container)
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
    // int number = 2;
    int number = 5;

    Solution solution;
    auto bit_num = solution.countBits(number);
    DisplayElement(bit_num);

    return 0;
}
