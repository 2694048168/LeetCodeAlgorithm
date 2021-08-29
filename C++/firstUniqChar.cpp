/**
 * @File    : firstUniqChar.cpp
 * @Brief   : 字符串中的第一个唯一字符
 * @Link    : https://leetcode-cn.com/problems/first-unique-character-in-a-string/
 * @Author  : Wei Li
 * @Date    : 2021-08-29
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<int, int> position;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (position.count(s[i]))
            {
                position[s[i]] = -1;
            }
            else
            {
                position[s[i]] = i;
            }
        }
        int first = n;
        // for (auto [_, pos] : position)  // std==C++17
        for (auto pos : position)
        {
            if (pos.second != -1 && pos.second < first)
            {
                first = pos.second;
            }
        }
        if (first == n)
        {
            first = -1;
        }
        return first;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::string str = "leetcode";
    std::string str = "loveleetcode";

    Solution solution;
    auto first_uniq_char = solution.firstUniqChar(str);
    std::cout << "The solution of this problem is " << first_uniq_char << std::endl;

    return 0;
}
