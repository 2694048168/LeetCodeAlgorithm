/**
 * @File    : AllOne.cpp
 * @Brief   : 全 O(1) 的数据结构
 * @Link    : https://leetcode-cn.com/problems/all-oone-data-structure/
 * @Author  : Wei Li
 * @Date    : 2021-08-03
*/

#include <iostream>
#include <string>
#include <unordered_map>

class AllOne
{
    struct kNode;
    struct vNode;

    struct kNode
    {
        std::string key;
        kNode *prev;
        kNode *next;
        vNode *parent;
        kNode(std::string _key = std::string()) : key(_key)
        {
            prev = NULL;
            next = NULL;
            parent = NULL;
        }
    };

    struct vNode
    {
        int val;
        vNode *prev;
        vNode *next;
        kNode *child;
        vNode(int _val = 0)
        {
            val = _val;
            next = NULL;
            prev = NULL;
            child = NULL;
        }
    };

private:
    vNode zero;
    std::unordered_map<std::string, kNode *> dict;

    template <typename T>
    inline void insert(T *n1, T *n2)
    {
        n2->next = n1->next;
        n1->next->prev = n2;
        n2->prev = n1;
        n1->next = n2;
    }

    template <typename T>
    inline void del(T *n1)
    {
        remove(n1);
        delete n1;
    }

    template <typename T>
    inline void remove(T *n1)
    {
        n1->next->prev = n1->prev;
        n1->prev->next = n1->next;
    }

    void addchild(vNode *vcur, kNode *cur)
    {
        cur->parent = vcur;
        if (vcur->child == NULL)
        {
            vcur->child = cur;
            cur->prev = cur;
            cur->next = cur;
        }
        else
        {
            insert(vcur->child, cur);
        }
    }

public:
    /** Initialize your data structure here. */
    AllOne()
    {
        zero.prev = &zero;
        zero.next = &zero;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(std::string key)
    {
        if (dict.count(key) == 0)
        {
            kNode *cur = new kNode(key);
            dict[key] = cur;
            if (zero.next == &zero || zero.next->val > 1)
            {
                insert(&zero, new vNode(1));
                addchild(zero.next, cur);
            }
            else
            {
                addchild(zero.next, cur);
            }
            return;
        }
        kNode *cur = dict[key];
        vNode *vcur = cur->parent;
        if (cur->next == cur)
        {
            if (vcur->next->val == vcur->val + 1)
            {
                addchild(vcur->next, cur);
                del(vcur);
            }
            else
            {
                vcur->val++;
            }
        }
        else
        {
            if (vcur->child == cur)
            {
                vcur->child = cur->next;
            }
            remove(cur);
            if (vcur->next->val == vcur->val + 1)
            {
                addchild(vcur->next, cur);
            }
            else
            {
                insert(vcur, new vNode(vcur->val + 1));
                addchild(vcur->next, cur);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(std::string key)
    {
        if (dict.count(key) == 0)
        {
            return;
        }
        kNode *cur = dict[key];
        vNode *vcur = cur->parent;
        if (cur->next == cur)
        {
            if (vcur->val == 1)
            {
                del(vcur);
                delete cur;
                dict.erase(key);
            }
            else if (vcur->prev->val == vcur->val - 1)
            {
                addchild(vcur->prev, cur);
                del(vcur);
            }
            else
            {
                vcur->val--;
            }
        }
        else
        {
            if (vcur->child == cur)
            {
                vcur->child = cur->next;
            }
            remove(cur);
            if (vcur->val == 1)
            {
                delete cur;
            }
            else if (vcur->prev->val == vcur->val - 1)
            {
                addchild(vcur->prev, cur);
            }
            else
            {
                insert(vcur->prev, new vNode(vcur->val - 1));
                addchild(vcur->prev, cur);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    std::string getMaxKey()
    {
        if (zero.prev == &zero)
        {
            return "";
        }
        return zero.prev->child->key;
    }

    /** Returns one of the keys with Minimal value. */
    std::string getMinKey()
    {
        if (zero.next == &zero)
        {
            return "";
        }
        return zero.next->child->key;
    }
    ~AllOne()
    {
        vNode *vcur = zero.next;
        while (vcur != &zero)
        {
            // cout<<vcur->val<<":";
            kNode *kcur = vcur->child;
            if (kcur)
            {
                do
                {
                    // cout<<kcur->key<<" ";
                    kNode *ktmp = kcur;
                    kcur = kcur->next;
                    delete ktmp;
                } while (kcur != vcur->child);
                // cout<<endl;
            }
            vNode *vtmp = vcur;
            vcur = vcur->next;
            delete vtmp;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
