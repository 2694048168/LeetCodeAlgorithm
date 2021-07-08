/**
 * @File    : findLongestWord.cpp
 * @Brief   : 通过删除字母匹配到字典里最长单词 Ⅱ 双指针策略
 * @Link    : https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 * @Author  : Wei Li
 * @Date    : 2021-07-08
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Solution
{
public:
    std::string findLongestWord(std::string str, std::vector<std::string>& dictionary)
    {
        // 字符串的长度从大到小排序，且字符串符合字典序       
        auto cmp = [&](std::string& a, std::string& b)
        {
            if (a.size() == b.size())
            {
                return a < b;
            }
            return a.size() > b.size();
        };
        std::sort(dictionary.begin(), dictionary.end(), cmp);

        int ds_len = 0, s_ptr = 0, d_ptr = 0;
        // 双指针策略遍历字典
        for (size_t i = 0; i < dictionary.size(); ++i)
        {
            // 当前字典的字符串的长度
            ds_len = dictionary[i].size();

            while (s_ptr < str.size() && d_ptr < ds_len)
            {
                // 存在相等的字母
                if (str[s_ptr] == dictionary[i][d_ptr])
                {
                    // 且已经到达当前字符串的末尾，即存在，因为已经排序，所以第一个符合条件的即为答案
                    if (d_ptr == ds_len - 1)
                    {
                        return dictionary[i];
                    }
                    //当前字典的字符串的下一个字母
                    ++d_ptr;
                }
                //匹配被查找字符串的下一个字母
                ++s_ptr;
            }
            //比较字典的下一个字符串，被查找字符串的s_ptr归零
            s_ptr = 0;
            //进行字典的下一个字符串比较，d_ptr归零
            d_ptr = 0;
        }
        return "";
    }
};


// --------------------------------
int main(int argc, char** argv)
{
    std::string str = "abpcplea";
    // std::vector<std::string> dictionary = {"ale", "apple", "monkey", "plea"};
    std::vector<std::string> dictionary = {"a", "b", "c"};

    auto solution = Solution();
    std::string longest_word = solution.findLongestWord(str, dictionary);
    std::cout << "The solution of this problem is : " << longest_word << std::endl;
    
    return 0;
}