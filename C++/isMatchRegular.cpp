/**
 * @File    : isMatchRegular.cpp
 * @Brief   : 正则表达式匹配
 * @Link    : https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-30
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j)
        {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str = "aa";
    std::string match_str = "a*";

    Solution solution; 
    auto check_match_regular = solution.isMatch(str, match_str);
    std::cout << "The solution of this problem is " << std::boolalpha << check_match_regular << std::endl;

    return 0;
}
