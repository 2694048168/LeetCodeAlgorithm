/**
 * @File    : reverseLeftWords.cpp
 * @Brief   :  II. 左旋转字符串
 * @Link    : https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-04
*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string reverseLeftWords(std::string s, int n)
    {
        std::reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::string str = "abcdefg";
    int k = 2;

    Solution solution;
    auto reverse_left_words = solution.reverseLeftWords(str, k);
    std::cout << "The solution of this problem is " << reverse_left_words << std::endl;

    return 0;
}
