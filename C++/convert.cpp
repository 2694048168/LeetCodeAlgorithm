/**
 * @File    : convert.cpp
 * @Brief   : Z 字形变换
 * @Link    : https://leetcode-cn.com/problems/zigzag-conversion/
 * @Author  : Wei Li
 * @Date    : 2021-08-16
*/

#include <iostream>
#include <string>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1)
            return s;

        std::string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::string str = "PAYPALISHIRING";
    int num_rows = 3;

    Solution solution;
    std::string convert_z = solution.convert(str, num_rows);
    std::cout << "The solution of this problem is " << convert_z << std::endl;

    return 0;
}
