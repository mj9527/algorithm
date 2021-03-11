//
// Created by mjzheng on 2020/6/17.
//

#ifndef ILIVE_IM_SVR_ZEROEVENTODD_H
#define ILIVE_IM_SVR_ZEROEVENTODD_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>
using namespace std;

namespace MultiThread {
    class ZeroEvenOdd {
    private:
        int n;
        mutex mu;
        condition_variable cond;

        bool is0,is1,is2;
    public:
        ZeroEvenOdd(int n) {
            this->n = n;
            is0=true;
            is1=false;
            is2=false;
        }

        // printNumber(x) outputs "x", where x is an integer.
        void zero(function<void(int)> printNumber) {
            for(int i=0;i<n;i++)
            {
                unique_lock<mutex> lk(mu);
                cond.wait(lk,[this](){return is0;});
                printNumber(0);
                if(i%2) is2=true;
                else is1=true;
                is0=false;
                cond.notify_all();

            }
        }

        void odd(function<void(int)> printNumber) {
            int num;
            if(n%2) num=n/2+1;
            else num=n/2;
            for(int i=0;i<num;i++)
            {
                unique_lock<mutex> lk(mu);
                cond.wait(lk,[this](){return is1;});
                printNumber(i*2+1);

                is1=false,is0=true;
                cond.notify_all();
            }
        }

        void even(function<void(int)> printNumber) {
            int num=n/2;

            for(int i=1;i<=num;i++)
            {
                unique_lock<mutex> lk(mu);
                cond.wait(lk,[this](){return is2;});
                printNumber(i*2);

                is2=false,is0=true;
                cond.notify_all();
            }
        }
    };

    int testZeroEvenOdd()
    {
        std::function<void(int) > f1= [](int x) {printf("%d", x); };
        ZeroEvenOdd obj(5);
        thread t1(std::bind(&ZeroEvenOdd::zero,&obj,f1));
        thread t2(std::bind(&ZeroEvenOdd::even, &obj,f1));
        thread t3(std::bind(&ZeroEvenOdd::odd, &obj,f1));
        t1.join();
        t2.join();
        t3.join();
        return 0;
    }
}

#endif //ILIVE_IM_SVR_ZEROEVENTODD_H
