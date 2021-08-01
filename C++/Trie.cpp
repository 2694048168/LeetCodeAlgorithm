/**
 * @File    : Trie.cpp
 * @Brief   : 实现 Trie (前缀树)
 * @Link    : https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
*/

#include <iostream>
#include <string>

class TrieNode
{
public:
    TrieNode *childNode[26];
    bool isVal;
    TrieNode() : isVal(false)
    {
        for (int i = 0; i < 26; ++i)
        {
            childNode[i] = nullptr;
        }
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}
    // 向字典树插入一个词
    void insert(std::string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!temp->childNode[word[i] - 'a'])
            {
                temp->childNode[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->childNode[word[i] - 'a'];
        }
        temp->isVal = true;
    }
    // 判断字典树里是否有一个词
    bool search(std::string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!temp)
            {
                break;
            }
            temp = temp->childNode[word[i] - 'a'];
        }
        return temp ? temp->isVal : false;
    }
    // 判断字典树是否有一个以词开始的前缀
    bool startsWith(std::string prefix)
    {
        TrieNode *temp = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (!temp)
            {
                break;
            }
            temp = temp->childNode[prefix[i] - 'a'];
        }
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
