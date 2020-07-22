//
// Created by mjzheng on 2020/6/12.
//

#ifndef ALGORITHM_SINGLETON_H
#define ALGORITHM_SINGLETON_H

#include <mutex>
#include <iostream>
#include <thread>

using namespace std;

class Singleton {
private:
    Singleton(int other) {
        a = other;
    }

    Singleton(const Singleton& other) =delete; // 拷贝构造函数

    Singleton& operator=(const Singleton& other) = delete; //// 赋值函数

public:
    ~Singleton() {}

    static Singleton* GetInstance() {
        if (nullptr == m_singleton) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (nullptr == m_singleton) {
                m_singleton = new Singleton(7);
            }
        }
        return m_singleton;
    }

    static Singleton* GetInstance2() {
        static Singleton instance(7);
        return &instance;
    }

private:
    static Singleton* m_singleton;
    static std::mutex m_mutex;
    int a;
};

Singleton* Singleton::m_singleton = nullptr;
std::mutex Singleton::m_mutex;

void ThreadRun(int a, int b, int c) {
    std::cout << a+b+c << std::endl;
}

void TestThread() {
    int a = 1;
    int b = 2;
    int c = 3;
    std::thread th1(ThreadRun, a, b, c);
    th1.join();

    std::thread th2(ThreadRun, a, b, 8);
    th2.join();
}

class A final {
public:
    A() {
        std::cout << "construct A" << std::endl;
    }
    ~A() {
        std::cout << "destory A" << std::endl;
    }
private:
    int a;
};

void TestSmartPointer() {
    std::unique_ptr<A> p(new A);
    std::shared_ptr<A> p1(new A);
}

void TestSingleton() {
    Singleton* p1 = Singleton::GetInstance();
    Singleton* p2 = Singleton::GetInstance();
    if (p1 == p2) {
        std::cout << "same" << std::endl;
    }

    Singleton* p3 = Singleton::GetInstance2();
    Singleton* p4 = Singleton::GetInstance2();
    if (p3 == p4) {
        std::cout << "same" << std::endl;
    }

//TestThread();
//TestSmartPointer();

}


#endif //ALGORITHM_SINGLETON_H
