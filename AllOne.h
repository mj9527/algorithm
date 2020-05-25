//
// Created by 郑俊明 on 2020/5/6.
//

#ifndef ALGORITHM_ALLONE_H
#define ALGORITHM_ALLONE_H


#include <map>
#include <string>


class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        std::map<string, int>::iterator iter = m_ls.find(key);
        if (iter != m_ls.end()) {
            iter->second += 1;
        } else {
            m_ls.insert(std::make_pair(key, 1));
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        std::map<string, int>::iterator iter = m_ls.find(key);
        if (iter != m_ls.end()) {
            if (iter->second == 1) {
                // erase
                m_ls.erase(iter);


            } else {
                iter->second -= 1;
            }
        } else {
           // do nothing
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {

    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {

    }

private:
    std::map<string, int> m_ls;
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
