/**
 * @File    : permutation.cpp
 * @Brief   : 字符串的排列
 * @Link    : https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-29
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool nextPermutation(std::string &s)
    {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1])
        {
            i--;
        }
        if (i < 0)
        {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j])
        {
            j--;
        }
        std::swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    std::vector<std::string> permutation(std::string s)
    {
        std::vector<std::string> ret;
        sort(s.begin(), s.end());
        do
        {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// ----------------------------
int main(int argc, char **argv)
{
    std::string str = "abc";

    Solution solution;
    auto str_permutation = solution.permutation(str);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(str_permutation);

    return 0;
}
