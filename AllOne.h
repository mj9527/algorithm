//
// Created by 郑俊明 on 2020/5/6.
//

#ifndef ALGORITHM_ALLONE_H
#define ALGORITHM_ALLONE_H


#include <map>
#include <string>
#include <set>
#include <list>

using namespace std;


//你实现一个数据结构支持以下操作：
//
//Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
//Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否则使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
//GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串"" 。
//GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。

struct Node {
    int value;
    set<string> keys;
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto iter = m_map.find(key);
        if (iter != m_map.end()) {

            auto p = iter->second;
            auto q = next(p);
            if (q == m_lst.end() || q->value != p->value +1) {
                Node t;
                t.value = p->value + 1;
                q = m_lst.insert(q, t);
            }
            q->keys.insert(key);
            m_map[key] = q;

            p->keys.erase(key);
            if (p->keys.empty()) {
                m_lst.erase(p);
            }

        } else {
            if (m_lst.empty() || m_lst.front().value != 1) {
                Node t;
                t.value = 1;
                t.keys.insert(key);
                m_lst.push_front(t);
            } else {
                m_lst.front().keys.insert(key);
            }
            m_map[key] = m_lst.begin();
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto iter = m_map.find(key);
        if (iter == m_map.end()) {
            return ;
        }
        auto lit = iter->second;

        if(lit->value > 1){
            auto pit = prev(lit);
            if (lit == m_lst.begin() || pit->value != lit->value - 1){
                set<string> unset;
                pit = m_lst.insert(lit, {lit->value - 1, unset});
            }
            pit->keys.insert(key);
            m_map[key] = pit;
        } else {
            m_map.erase(key);
        }

        lit->keys.erase(key);
        if(lit->keys.empty()) {
            m_lst.erase(lit);
        }

    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return m_lst.empty()? "" : *m_lst.back().keys.cbegin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return m_lst.empty()? "" : *m_lst.front().keys.cbegin();
    }

private:
    map<string, list<Node>::iterator> m_map;
    list<Node> m_lst;
};

void TestAllOne() {

    AllOne* obj = new AllOne();
    string key = "name";
    obj->inc(key);
    obj->dec(key);
    string param_3 = obj->getMaxKey();
    string param_4 = obj->getMinKey();
}


#endif //ALGORITHM_ALLONE_H
