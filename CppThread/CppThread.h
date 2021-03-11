//
// Created by mjzheng on 2021/3/11.
//

#ifndef ALGORITHM_CPPTHREAD_H
#define ALGORITHM_CPPTHREAD_H

#include <thread>
#include <iostream>

namespace CppThread {

    void ThreadFunc(int a, int b) {
        std::cout << a  << " " << b << std::endl;
    }

    void testThread() {
        std::thread t(ThreadFunc, 100, 200);
        t.join();
    }
}

#endif //ALGORITHM_CPPTHREAD_H
