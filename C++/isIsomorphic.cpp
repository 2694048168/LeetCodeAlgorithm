/**
 * @File    : isIsomorphic.cpp
 * @Brief   : 同构字符串
 * @Link    : https://leetcode-cn.com/problems/isomorphic-strings/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::vector<int> s_first_index(256, 0), t_first_index(256, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            if (s_first_index[s[i]] != t_first_index[t[i]])
            {
                return false;
            }
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
        }
        return true;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    std::string s = "paper", t = "title";

    Solution solution;
    bool check_isomorphic = solution.isIsomorphic(s, t);
    std::cout << "The solution of this problem is " << std::boolalpha << check_isomorphic << std::endl;

    return 0;
}
