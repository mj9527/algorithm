//
// Created by mjzheng on 2020/7/31.
//

#ifndef ALGORITHM_SEQUENCEPRINT_H
#define ALGORITHM_SEQUENCEPRINT_H

#include <iostream>
#include <thread>
#include <atomic>

atomic_llong total{0}; //


class SequencePrint {
public:

    SequencePrint() {

    }

    void one() {
        autoCount(1, "one");
    }

    void two() {
        autoCount(2, "two");
    }
    void three() {
        autoCount(3, "three");
    }

    void autoCount(int index, const std::string& tips) {
        std::unique_lock<std::mutex> lk(m_mutex);
        m_cv.wait(lk, [this, &index](){return counter==index;});
        //std::cout << index << " "<< this << std::endl;
        std::cout << tips;
        counter++;
        m_cv.notify_one();
    }

    void first(function<void()> printFirst) {

        printFirst();
        m_lock1.unlock();
        // printFirst() outputs "first". Do not change or remove this line
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m_lock1);
        printSecond();
        m_lock2.unlock();
        // printSecond() outputs "second". Do not change or remove this line.
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock2(m_lock2);
        std::unique_lock<std::mutex> lock1(m_lock1);
        printThird();
    }

private:
    std::mutex m_lock1;
    std::mutex m_lock2;

private:
    std::condition_variable m_cv;
    std::mutex m_mutex;
    int counter {1};
};

//使用std::atomic_flag的自旋锁互斥实现
class spinlock_mutex
{
    std::atomic_flag flag;
public:
    spinlock_mutex():flag(ATOMIC_FLAG_INIT) {}
    void lock()
    {
        while(flag.test_and_set(std::memory_order_acquire));
    }
    void unlock()
    {
        flag.clear(std::memory_order_release);
    }
};

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
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            m_mutex2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            m_mutex2.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            m_mutex1.unlock();
        }
    }

private:
    std::mutex m_mutex1;
    std::mutex m_mutex2;
};

void TestFunction(function<void()> f) {
    f();
}

void SayHello() {
    std::cout << "hello " << std::endl;
}

void TestSequence() {

    TestFunction(SayHello);

    SequencePrint s;
    thread t3(&SequencePrint::three, &s);
    thread t1(&SequencePrint::one, &s);
    thread t2(&SequencePrint::two, &s);

    t1.join();
    t2.join();
    t3.join();


//    for (int i=1; i<100; i++) {
//        thread t(&SequencePrint::autoCount, &s, i);
//        t.join();
//    }
}

void AddTotal(int index) {
    char buf[256];
    sprintf(buf, "%d %d %d\n", index, std::this_thread::get_id());
    std::cout << buf;
    for (long long i=0; i<100000000LL; i++) {
        total += i;
    }
    std::cout << total << std::endl;
}

void TestAdd() {
    thread t1(AddTotal, 1);
    thread t2(AddTotal, 2);


    std::cout << t1.get_id() << " " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
    std::cout << total << std::endl;
}

#endif //ALGORITHM_SEQUENCEPRINT_H
