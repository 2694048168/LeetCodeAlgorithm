/**
 * @File    : longestAwesome.cpp
 * @Brief   : 出最长的超赞子字符串
 * @Link    : https://leetcode-cn.com/problems/find-longest-awesome-substring/
 * @Author  : Wei Li
 * @Date    : 2021-08-30
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int longestAwesome(std::string s)
    {
        int n = s.size();
        std::unordered_map<int, int> prefix = {{0, -1}};
        int ans = 0;
        int sequence = 0;
        for (int j = 0; j < n; ++j)
        {
            int digit = s[j] - '0';
            sequence ^= (1 << digit);
            if (prefix.count(sequence))
            {
                ans = std::max(ans, j - prefix[sequence]);
            }
            else
            {
                prefix[sequence] = j;
            }
            for (int k = 0; k < 10; ++k)
            {
                if (prefix.count(sequence ^ (1 << k)))
                {
                    ans = std::max(ans, j - prefix[sequence ^ (1 << k)]);
                }
            }
        }
        return ans;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string str = "12345678";
    std::string str = "213123";

    Solution solution;
    auto longest_some = solution.longestAwesome(str);
    std::cout << "The solution of this problem is " << longest_some << std::endl;

    return 0;
}
