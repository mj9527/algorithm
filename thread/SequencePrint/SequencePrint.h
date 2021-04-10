//
// Created by mjzheng on 2020/7/31.
//

#ifndef ALGORITHM_SEQUENCEPRINT_H
#define ALGORITHM_SEQUENCEPRINT_H

#include <iostream>
#include <thread>
#include <atomic>

atomic_llong total{0}; //

namespace MultiThread {
    class SequencePrint {
    public:
        SequencePrint() {
            m_lock1.lock();
            m_lock2.lock();
        }

        void first(function<void()> printFirst) {
            std::cout << "start first" << std::endl;
            printFirst();
            m_lock1.unlock();
            // printFirst() outputs "first". Do not change or remove this line
        }

        void second(function<void()> printSecond) {
            std::cout << "start end" << std::endl;
            std::unique_lock<std::mutex> lock(m_lock1);
            printSecond();
            m_lock2.unlock();
            // printSecond() outputs "second". Do not change or remove this line.
        }

        void third(function<void()> printThird) {
            std::cout << "start third" << std::endl;
            std::unique_lock<std::mutex> lock2(m_lock2);
            printThird();
        }

    private:
        std::mutex m_lock1;
        std::mutex m_lock2;
    };

    void printStr(const std::string& str) {
        std::cout << str << std::endl;
    }

    void printFirst() {
        printStr("first");
    }

    void printSecond() {
        printStr("second");
    }

    void printThird() {
        printStr("Third");
    }

    void TestSequence() {
        SequencePrint s;
        thread t3(&SequencePrint::third, &s, printThird);
        thread t2(&SequencePrint::second, &s, printSecond);
        thread t1(&SequencePrint::first, &s, printFirst);

        t1.join();
        t2.join();
        t3.join();
    }
}

#endif //ALGORITHM_SEQUENCEPRINT_H
