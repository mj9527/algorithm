//
// Created by mjzheng on 2020/8/4.
//

#ifndef ALGORITHM_H2O_H
#define ALGORITHM_H2O_H

#include <thread>

class H2O {
public:
    H2O(int n) {
        this->n = n;
        h0 = true;
        h1 = false;
        o1 = false;
    }

    H2O(const std::string& str) {
        n = str.size() / 3;
        h0 = true;
        h1 = false;
        o1 = false;
    }

    H2O(const char* str) {
        n = strlen(str) / 3;
        h0 = true;
        h1 = false;
        o1 = false;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        for (int i=0; i<n; i++) {
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return (h0 || h1);});
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();

            if (h0) {
                h0 = false;
                h1 = true;
                o1 = false;
            } else if (h1){
                h0 = false;
                h1 = false;
                o1 = true;
            }
            cond.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {

        for (int i=0; i<n; i++) {
            std::unique_lock<std::mutex> lk(mu);
            cond.wait(lk, [this](){ return o1;});

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();

            h0 = true;
            h1 = false;
            o1 = false;

            cond.notify_all();
        }
    }
private:
    int n;
    mutex mu;
    condition_variable cond;
    bool h0,h1,o1;
};

void TestH2O() {
    H2O water("OOHHHH");
    std::function<void()> releaseHydrogen = []() {printf("H");};
    std::thread h1(&H2O::hydrogen, &water, releaseHydrogen);
    std::thread h2(&H2O::hydrogen, &water, releaseHydrogen);

    std::function<void()> releaseOxygen = []() {printf("O");};
    std::thread h3(&H2O::oxygen, &water, releaseOxygen);


    h1.join();
    h2.join();
    h3.join();

}


#endif //ALGORITHM_H2O_H
