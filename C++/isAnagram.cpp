/**
 * @File    : isAnagram.cpp
 * @Brief   : 有效的字母异位词
 * @Link    : https://leetcode-cn.com/problems/valid-anagram/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::vector<int> counts(26, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i])
            {
                return false;
            }
        }
        return true;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::string s = "anagram", t = "nagaram";
    std::string s = "rat", t = "car";

    Solution solution;
    bool check_anagram = solution.isAnagram(s, t);
    std::cout << "The solution of this problem is " << std::boolalpha << check_anagram << std::endl;

    return 0;
}
