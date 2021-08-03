/**
 * @File    : LRUCache.cpp
 * @Brief   : LRU 缓存机制
 * @Link    : https://leetcode-cn.com/problems/lru-cache/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>


class LRUCache
{
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
    std::list<std::pair<int, int>> cache;
    int size;

public:
    LRUCache(int capacity) : size(capacity) {}
    int get(int key)
    {
        auto it = hash.find(key);
        if (it == hash.end())
        {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    void put(int key, int value)
    {
        auto it = hash.find(key);
        if (it != hash.end())
        {
            it->second->second = value;
            return cache.splice(cache.begin(), cache, it->second);
        }
        cache.insert(cache.begin(), std::make_pair(key, value));
        hash[key] = cache.begin();
        if (cache.size() > size)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// ---------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
