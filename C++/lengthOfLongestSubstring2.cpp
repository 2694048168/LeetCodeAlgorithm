/**
 * @File    : lengthOfLongestSubstring2.cpp
 * @Brief   : 最长不含重复字符的子字符串
 * @Link    : https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-12
*/

#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int size = s.size(); //原始串的长度
        std::string str = "";     //子串
        int max = 0;         //最长子串的长度
        int t;               //保存 当前字符在子串中出现的位置
        for (int i = 0; i < size; i++)
        {
            t = str.find(s[i]); //查找 当前字符在子串中出现的位置
            if (t != -1)        //如果出现了
            {
                if (max < str.size()) //判断当前子串 与 历史最长串的大小
                    max = str.size();
                str.erase(0, t + 1); //去掉前t+1个字符
            }
            str += s[i]; //不管有没有出现，都需要将当前的字符添加到子串中
        }
        if (max < str.size()) //最终还是要判断一次，因为如果从来都没有重复过的话，就不会进入if(t != -1)，也不会更新max了
            max = str.size();
        return max;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str = "pwwkew";

    Solution solution;
    auto length_longest_substring = solution.lengthOfLongestSubstring(str);
    std::cout << "The solution of this problem is " << length_longest_substring << std::endl;

    return 0;
}
