//
// Created by mjzheng on 2020/7/30.
//

#ifndef ALGORITHM_PTRSAMPLE_H
#define ALGORITHM_PTRSAMPLE_H

#include <iostream>


class PtrSample {

};

void StudyPtr() {
    auto_ptr<int> p(new int(10));
    std::cout << *p << std::endl;
    {

    }
    auto_ptr<int> p1(p);
    std::cout << *p1 << std::endl;
    if (p.get() == nullptr) {
        std::cout << "right" << std::endl;
    }
    //std::cout << "agian" << *p << std::endl;


    unique_ptr<int> p2(new int(20));
    if (p2 == nullptr) {
        std::cout << "error" << std::endl;
    }
    p2.reset();

    shared_ptr<int> p3(new int(30));
    shared_ptr<int> p4(p3);
    std::cout << p4.use_count() << std::endl;

    weak_ptr<int> p5(p3);
    p3 = nullptr;
    std::cout << p5.use_count() << std::endl;
    p4 = nullptr;
    std::cout << p5.use_count() << std::endl;
}


#endif //ALGORITHM_PTRSAMPLE_H
