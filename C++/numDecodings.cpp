/**
 * @File    : numDecodings.cpp
 * @Brief   : 解码方法 动态规划
 * @Link    : https://leetcode-cn.com/problems/decode-ways/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int numDecodings(std::string s)
    {
        int n = s.length();
        if (n == 0)
        {
            return 0;
        }

        int prev = s[0] - '0';
        if (!prev)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }

        std::vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            int current = s[i - 1] - '0';
            if ((prev == 0 || prev > 2) && current == 0)
            {
                return 0;
            }
            if ((prev < 2 && prev > 0) || prev == 2 && current < 7)
            {
                if (current)
                {
                    dp[i] = dp[i - 2] + dp[i - 1];
                }
                else
                {
                    dp[i] = dp[i - 2];
                }
            }
            else
            {
                dp[i] = dp[i - 1];
            }

            prev = current;
        }
        return dp[n];
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // std::string str = "12";
    // std::string str = "226";
    std::string str = "06";

    Solution solution;
    auto num_decodeings = solution.numDecodings(str);
    std::cout << "The solution of this problem is " << num_decodeings << std::endl;

    return 0;
}
