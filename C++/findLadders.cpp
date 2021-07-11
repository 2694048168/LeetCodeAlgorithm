/**
 * @File    : findLadders.cpp
 * @Brief   : 单词接龙 II 广度优先搜索
 * @Link    : https://leetcode-cn.com/problems/word-ladder-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    // 主函数
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
    {
        std::vector<std::vector<std::string>> ans;
        std::unordered_set<std::string> dict;
        for (const auto &w : wordList)
        {
            dict.insert(w);
        }
        if (!dict.count(endWord))
        {
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        std::unordered_set<std::string> q1{beginWord}, q2{endWord};
        std::unordered_map<std::string, std::vector<std::string>> next;
        bool reversed = false, found = false;
        while (!q1.empty())
        {
            std::unordered_set<std::string> q;
            for (const auto &w : q1)
            {
                std::string s = w;
                for (size_t i = 0; i < s.size(); i++)
                {
                    char ch = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = j + 'a';
                        if (q2.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if (found)
            {
                break;
            }
            for (const auto &w : q)
            {
                dict.erase(w);
            }
            if (q.size() <= q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if (found)
        {
            std::vector<std::string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    // 辅函数
    void backtracking(const std::string &src, const std::string &dst, std::unordered_map<std::string, std::vector<std::string>> &next, std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (const auto &s : next[src])
        {
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        for (auto value = element->begin(); value != element->end(); ++value)
        {
            std::cout << *value << " ";
        }
    }
    std::cout << std::endl;
}

// ---------------------------------
int main(int argc, char **argv)
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    // std::vector<std::string> wordList{"hot","dot","dog","lot","log"};

    Solution solution;
    auto ladder_vec = solution.findLadders(beginWord, endWord, wordList);
    std::cout << "The solution of this problem is : " << std::endl;
    DisplayElement(ladder_vec);

    return 0;
}
