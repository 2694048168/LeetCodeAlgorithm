/**
 * @File    : firstUniqChar2.cpp
 * @Brief   : 第一个只出现一次的字符
 * @Link    : https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-06
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

class Solution
{
public:
    char firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> position;
        std::queue<std::pair<char, int>> q;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (!position.count(s[i]))
            {
                position[s[i]] = i;
                q.emplace(s[i], i);
            }
            else
            {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1)
                {
                    q.pop();
                }
            }
        }
        return q.empty() ? ' ' : q.front().first;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::string str = "abaccdeff";

    Solution solution;
    auto first_uniq_char = solution.firstUniqChar(str);
    std::cout << "The solution of this problem is " << first_uniq_char << std::endl;

    return 0;
}
