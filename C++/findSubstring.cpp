/**
 * @File    : findSubstring.cpp
 * @Brief   : 串联所有单词的子串
 * @Link    : https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
 * @Author  : Wei Li
 * @Date    : 2021-08-17
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
    {
        //特殊情况直接排除
        if (s.empty() || words.empty())
            return {};

        //存放结果的数组
        std::vector<int> result;

        //单词数组中的单词的大小，个数，以及总长度
        int one_word = words[0].size();
        int word_num = words.size();
        int all_len = one_word * word_num;

        //建立单词->单词个数的映射
        std::unordered_map<std::string, int> m1;
        for (const auto &w : words)
            m1[w]++;

        for (int i = 0; i < one_word; ++i)
        {
            //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            int left = i, right = i, count = 0;

            std::unordered_map<std::string, int> m2;

            //开始滑动窗口
            while (right + one_word <= s.size())
            {
                //从s中提取一个单词拷贝到w
                std::string w = s.substr(right, one_word);
                right += one_word; //窗口右边界右移一个单词的长度

                if (m1.count(w) == 0)
                { //此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    count = 0;
                    left = right;
                    m2.clear();
                }
                else
                { //该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;
                    while (m2.at(w) > m1.at(w)) //一个单词匹配多次，需要缩小窗口，也就是left右移
                    {
                        std::string t_w = s.substr(left, one_word);
                        count--;
                        m2[t_w]--;
                        left += one_word;
                    }
                    if (count == word_num)
                        result.push_back(left);
                }
            }
        }
        return result;
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

// -------------------------------
int main(int argc, char **argv)
{
    // std::string str = "barfoothefoobarman";
    // std::vector<std::string> words{"foo", "bar"};
    std::string str = "barfoofoobarthefoobarman";
    std::vector<std::string> words{"bar", "foo", "the"};

    Solution solution;
    auto find_substring = solution.findSubstring(str, words);
    DisplayElement(find_substring);

    return 0;
}
