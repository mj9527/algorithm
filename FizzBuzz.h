//
// Created by mjzheng on 2020/8/4.
//

#ifndef ALGORITHM_FIZZBUZZ_H
#define ALGORITHM_FIZZBUZZ_H

#include <condition_variable>
#include <mutex>


class FizzBuzz {
private:
    int n;
    std::condition_variable cond;
    std::mutex mu;
    int count;

public:
    FizzBuzz(int n) {
        this->n = n;
        count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (count<=n){
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return (count % 3 == 0) && (count % 5 !=0)|| (count>n);});
            if (count <= n) {
                printFizz();
                count++;
            }
            cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (count<=n){
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return (count % 3 != 0) && (count % 5 ==0) || (count>n); });
            if (count <= n) {
                printBuzz();
                count++;
            }
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (count<=n){
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return (count % 3 == 0) && (count % 5 ==0)|| (count>n);});
            if (count <=n ) {
                printFizzBuzz();
                count++;
            }

            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (count<=n){
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return (count % 3 != 0) && (count % 5 !=0)|| (count>n);});
            if (count <= n) {
                printNumber(count);
                count++;
            }
            cond.notify_all();
        }
    }
};

void TestFizzBuzz() {
    FizzBuzz f(10);
    std::function<void()> f1 = [](){printf("fizz")};
    std::thread t1(&FizzBuzz::fizz, &f, f1);

    std::function<void()> f2 = [](){printf("buzz")};
    std::thread t2(&FizzBuzz::buzz, &f, f2);

    std::function<void()> f3 = [](){printf("fizzbuzz")};
    std::thread t3(&FizzBuzz::fizzbuzz, &f, f3);

    std::function<void()> f4 = [](int i){printf("%d", i)};
    std::thread t4(&FizzBuzz::number, &f, f4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}


#endif //ALGORITHM_FIZZBUZZ_H
