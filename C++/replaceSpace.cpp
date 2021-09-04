/**
 * @File    : replaceSpace.cpp
 * @Brief   : 替换空格
 * @Link    : https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-04
*/

#include <iostream>
#include <string>

class Solution
{
public:
    std::string replaceSpace(std::string s)
    {
        int count = 0, len = s.size();
        // 统计空格数量
        for (char c : s)
        {
            if (c == ' ')
                count++;
        }
        // 修改 s 长度
        s.resize(len + 2 * count);
        // 倒序遍历修改
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--)
        {
            if (s[i] != ' ')
                s[j] = s[i];
            else
            {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::string str = "We are happy.";

    Solution solution;
    auto replace_space_str = solution.replaceSpace(str);
    std::cout << "The solution of this problem is " << replace_space_str << std::endl;

    return 0;
}
