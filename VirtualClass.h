//
// Created by 郑俊明 on 2020/6/5.
//

#ifndef ALGORITHM_VIRTUALCLASS_H
#define ALGORITHM_VIRTUALCLASS_H

#include <iostream>

using namespace std;

class VirtualClass {
public:
    void funcA() {
        std::cout << this << std::endl;
        std::cout << "funcA" << std::endl;
    }

    virtual void funcB() {
        std::cout << "funcB" << std::endl;
    }
};

void TestVirtual() {
    VirtualClass* p = nullptr;
    p->funcA();
    p->funcB();
}



#endif //ALGORITHM_VIRTUALCLASS_H
