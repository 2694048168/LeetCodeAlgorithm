/**
 * @File    : wordPattern.cpp
 * @Brief   : 单词规律
 * @Link    : https://leetcode-cn.com/problems/word-pattern/
 * @Author  : Wei Li
 * @Date    : 2021-08-29
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool wordPattern(std::string pattern, std::string str)
    {
        std::unordered_map<std::string, char> str2ch;
        std::unordered_map<char, std::string> ch2str;
        int m = str.length();
        int i = 0;
        for (auto ch : pattern)
        {
            if (i >= m)
            {
                return false;
            }
            int j = i;
            while (j < m && str[j] != ' ')
                j++;
            const std::string &tmp = str.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch)
            {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp)
            {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::string pattern = "abba";
    // std::string str = "dog cat cat dog";
    std::string str = "dog cat cat fish";

    Solution solution;
    bool check_word_pattern = solution.wordPattern(pattern, str);
    std::cout << "The solution of this problem is " << std::boolalpha << check_word_pattern << std::endl;

    return 0;
}
