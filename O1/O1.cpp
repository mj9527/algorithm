//
// Created by 郑俊明 on 2021/4/10.
//

#include "O1.h"

void O1::dec(std::string &key) {
    auto iter = m_map.find(key);
    if (iter == m_map.end()) {
        return ;
    }
    auto lit = iter->second;
    if (lit->value > 1) {
        auto pit = prev(lit);
        if (lit == m_lst.begin() || pit->value != lit->value - 1){
            std::set<std::string> unset;
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

void O1::inc(std::string &key) {
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {
        auto p = iter->second;
        auto q = next(p);
        if (q == m_lst.end() || q->value != p->value+1) {
            Node t;
            t.value = p->value+1;
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
    }
}

std::string O1::getMaxKey() {
    return m_lst.empty()? "" : *m_lst.front().keys.cbegin();
}

std::string O1::getMinKey() {
    return m_lst.empty()? "" : *m_lst.front().keys.cbegin();
}