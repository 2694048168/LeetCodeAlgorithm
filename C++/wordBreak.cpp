/**
 * @File    : wordBreak.cpp
 * @Brief   : 单词拆分 动态规划
 * @Link    : https://leetcode-cn.com/problems/word-break/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (const std::string &word : wordDict)
            {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word)
                {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string str = "leetcode";
    // std::vector<std::string> word_dict{{"leet"}, {"code"}};

    std::string str = "catsandog";
    std::vector<std::string> word_dict{{"cats"}, {"dog"}, {"sand"}, {"and"}, {"cat"}};

    Solution solution;
    bool check = solution.wordBreak(str, word_dict);
    std::cout << "The solution of this problem is " << std::boolalpha << check << std::endl;

    return 0;
}
