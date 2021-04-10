//
// Created by 郑俊明 on 2021/4/10.
//

#ifndef ALGORITHM_O1_H
#define ALGORITHM_O1_H

#include <string>
#include <set>
#include <list>
#include <unordered_map>

class O1 {
public:
    void inc(std::string& key);

    void dec(std::string& key);

    std::string getMinKey();

    std::string getMaxKey();

    struct Node{
        int value;
        std::set<std::string> keys;
    };

    std::list<Node> m_lst;
    std::unordered_map<std::string, std::list<Node>::iterator> m_map;
};


#endif //ALGORITHM_O1_H
