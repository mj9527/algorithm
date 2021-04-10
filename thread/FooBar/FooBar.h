//
// Created by mjzheng on 2021/3/11.
//

#ifndef ALGORITHM_FOOBAR_H
#define ALGORITHM_FOOBAR_H

#include <thread>

namespace MultiThread {
    class FooBar {
    private:
        int n;
    public:
        FooBar(int n) {
            this->n = n;
            m_mutex2.lock();
        }

        void foo(function<void()> printFoo) {

            for (int i = 0; i < n; i++) {
                m_mutex1.lock();
                printFoo();
                m_mutex2.unlock();
            }
        }

        void bar(function<void()> printBar) {
            for (int i = 0; i < n; i++) {
                m_mutex2.lock();
                printBar();
                m_mutex1.unlock();
            }
        }

    private:
        std::mutex m_mutex1;
        std::mutex m_mutex2;
    };

    void printFoo() {
        std::cout << "Foo" << std::endl;
    };

    void printBar() {
        std::cout << "Bar" << std::endl;
    }

    void testFooBar() {
        FooBar s(10);
        std::thread t1(&FooBar::foo, &s, printFoo);
        std::thread t2(&FooBar::bar, &s, printBar);
        t1.join();
        t2.join();
    }
}
#endif //ALGORITHM_FOOBAR_H
