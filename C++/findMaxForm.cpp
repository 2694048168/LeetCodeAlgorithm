/**
 * @File    : findMaxForm.cpp
 * @Brief   : 一和零 背包问题 - 动态规划
 * @Link    : https://leetcode-cn.com/problems/ones-and-zeroes/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> getZerosOnes(std::string &str)
    {
        std::vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++)
        {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(std::vector<std::string> &strs, int m, int n)
    {
        int length = strs.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i < length; i++)
        {
            std::vector<int> &&zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = std::max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    Solution solution;
    auto max_form = solution.findMaxForm(strs, m, n);
    std::cout << "The solution of this problem is " << max_form << std::endl;

    return 0;
}
