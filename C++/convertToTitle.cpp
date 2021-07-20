/**
 * @File    : convertToTitle.cpp
 * @Brief   : Excel表列名称 数学问题
 * @Link    : https://leetcode-cn.com/problems/excel-sheet-column-title/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        std::string ans;
        while (columnNumber > 0)
        {
            --columnNumber;
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int column_num = 1;
    // int column_num = 287;
    // int column_num = 28;
    // int column_num = 701;
    int column_num = 2147483647;

    Solution solution;
    std::string column_title = solution.convertToTitle(column_num);
    std::cout << "The solution of this problem is " << column_title << std::endl;

    return 0;
}
