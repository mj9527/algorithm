//
// Created by mjzheng on 2020/8/4.
//

#ifndef ALGORITHM_H2O_H
#define ALGORITHM_H2O_H

#include <thread>
#include <mutex>

namespace MultiThread {
    class H2O {
    private:
        int h, o;
        std::mutex hm, om;
        std::condition_variable cv;
    public:
        H2O() {
            h = 0;
            o = 0;
            cv.notify_all();
        }

        void hydrogen(function<void()> releaseHydrogen) {

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            auto lk = std::unique_lock<std::mutex>(hm);
            cv.wait(lk, [this]{return o+1>=h;}); //H分子还没有饱和
            releaseHydrogen();
            h += 1;
            lk.unlock();
            cv.notify_all();
        }

        void oxygen(function<void()> releaseOxygen) {

            // releaseOxygen() outputs "O". Do not change or remove this line.
            auto lk = std::unique_lock<std::mutex>(om);
            cv.wait(lk, [this]{return h>=o;}); //O分子还没有饱和
            releaseOxygen();
            o += 2;
            lk.unlock();
            cv.notify_all();
        }
    };

    void TestH2O() {
        H2O water;
        std::function<void()> releaseHydrogen = []() {printf("H");};
        std::function<void()> releaseOxygen = []() {printf("O");};
        std::thread h1(&H2O::hydrogen, &water, releaseHydrogen);
        std::thread h3(&H2O::hydrogen, &water, releaseHydrogen);
        std::thread h2(&H2O::hydrogen, &water, releaseOxygen);

        h1.join();
        h2.join();
        h3.join();
    }
}

#endif //ALGORITHM_H2O_H
