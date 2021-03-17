//
// Created by 郑俊明 on 2020/6/16.
//

#ifndef ALGORITHM_ZEROEVENODD_H
#define ALGORITHM_ZEROEVENODD_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

using namespace std;


class ZeroEvenOdd {

private:
    int n;
    std::mutex mutex_t;
    std::condition_variable cond;
    bool is0 = true;
    bool is1 = true;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lk(mutex_t);
            cond.wait(lk, [this]() {return is0; });
            printNumber(0);
            is0 = false;
            cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        if (n == 0)return;
        for (int i = 1; i <= n; i++)
        {
            std::unique_lock<std::mutex> lk(mutex_t);
            cond.wait(lk, [this]() {return !is0&&is1; });
            if (i % 2)
            {
                printNumber(i);
                is0 = true;
                is1 = false;
            }

            cond.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        if (n == 0)return;
        for (int i = 1; i <= n; i++)
        {
            std::unique_lock<std::mutex> lk(mutex_t);
            cond.wait(lk, [this]() {return !is0 && !is1; });
            if (i % 2 == 0)
            {
                printNumber(i);
                is0 = true;
                is1 = true;
            }

            cond.notify_all();
        }

    }
};


void TestZero() {
    std::function<void(int)> f1 = [](int x) { printf("%d", x); };
    ZeroEvenOdd obj(5);
    thread t1(std::bind(&ZeroEvenOdd::zero, &obj, f1));
    thread t2(std::bind(&ZeroEvenOdd::even, &obj, f1));
    thread t3(std::bind(&ZeroEvenOdd::odd, &obj, f1));
    t1.join();
    t2.join();
    t3.join();
}

#endif