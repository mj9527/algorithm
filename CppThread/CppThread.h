//
// Created by mjzheng on 2021/3/11.
//

#ifndef ALGORITHM_CPPTHREAD_H
#define ALGORITHM_CPPTHREAD_H

#include <thread>
#include <iostream>

namespace CppThread {
    void TestThreadModel();

    class ThreadModel {
    public:
        ThreadModel();

        virtual ~ThreadModel();

    public:
        int StartThread();

        int StopThread();

        int WakeupThread();

    protected:
        void Run();

        void SampleStack();

    private:
        std::condition_variable work_event_;
        std::mutex work_mutex_;

        std::condition_variable exit_event_;
        std::mutex exit_mutex_;

    private:
        std::atomic<bool> wakeup_flag_;
        std::atomic<bool> exit_flag_;
        std::atomic<bool> is_running_;
    };
}

#endif //ALGORITHM_CPPTHREAD_H
