/**
 * @File    : reverseWords.cpp
 * @Brief   : 翻转单词顺序
 * @Link    : https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-14
*/

#include <iostream>
#include <string>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::string res;
        int n = s.size();
        if (n == 0)
            return res;
        int right = n - 1;
        while (right >= 0)
        {
            //从后往前寻找第一字符
            while (right >= 0 && s[right] == ' ')
                right--;
            if (right < 0)
                break;

            //从后往前寻找第一个空格
            int left = right;
            while (left >= 0 && s[left] != ' ')
                left--;

            //添加单词到结果
            res += s.substr(left + 1, right - left);
            res += ' ';

            //继续往前分割单词
            right = left;
        }
        //去除最后一个字符空格
        if (!res.empty())
            res.pop_back();
        return res;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::string str = "the sky is blue";

    Solution solution;
    auto reverse_words = solution.reverseWords(str);
    std::cout << "The solution of this problem is : " << reverse_words << std::endl;

    return 0;
}
