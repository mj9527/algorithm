//
// Created by 郑俊明 on 2020/6/3.
//

#ifndef ALGORITHM_LISTOPER_H
#define ALGORITHM_LISTOPER_H

#include <list>
#include <iostream>
#include <set>

using namespace std;

void TestListOper() {
    list<int> ls;
    auto p = ls.begin();
    for (int i=0; i<10; i++) {
        ls.push_back(i);
    }
    std::cout << std::endl;

    auto iter = ls.begin();
    while (iter != ls.end()) {
        if (*iter == 5) {
            auto p = next(iter);
            std::swap(*iter, *p);
            break;
        }
        iter = next(iter);
    }

    iter = ls.begin();
    for (; iter != ls.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void TestSet() {
    set<int> s;
    s.insert(1);
    s.insert(8);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(9);
    auto iter = s.begin();
    for (; iter != s.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void TestMap() {
    map<int, int> s;
    s.insert(std::make_pair(1,1));
    s.insert(std::make_pair(8,8));
    s.insert(std::make_pair(2,2));
    s.insert(std::make_pair(5,5));
    s.insert(std::make_pair(3,3));
    s.insert(std::make_pair(9,9));

    auto iter = s.begin();
    for (; iter != s.end(); iter++) {
        std::cout << iter->first << " " << iter->second << " ";
    }
    std::cout << std::endl;


}


#endif //ALGORITHM_LISTOPER_H
