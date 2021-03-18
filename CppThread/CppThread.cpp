//
// Created by 郑俊明 on 2021/3/17.
//

#include "CppThread.h"

namespace CppThread {

void TestThreadModel() {
    ThreadModel s;
    s.StartThread();
    for (int i=0; i<3; i++) {
        s.WakeupThread();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000*5));
    }
    s.StopThread();
}

ThreadModel::ThreadModel() {
    exit_flag_ = true;
    is_running_ = false;
}

ThreadModel::~ThreadModel() {

}

int ThreadModel::StartThread() {
    // jadge thread running state

    exit_flag_ = false;
    std::thread th([this]{
        Run();
    });
    th.detach();
    return 0;
}

int ThreadModel::StopThread() {
    // jadge thread running state

    std::cout << "start stop thread" << std::endl;

    exit_flag_ = true;
    work_event_.condition.notify_one();
    
    std::unique_lock<std::mutex> locker(exit_event_.mu);
    exit_event_.condition.wait(locker, [this] {
        return !is_running_;
    });

    std::cout << "finish stop thread" << std::endl;
    return 0;
}

int ThreadModel::WakeupThread() {
    wakeup_flag_ = true;
    work_event_.condition.notify_one();
}

void ThreadModel::Run() {
    is_running_ = true;
    while (!exit_flag_) {
        std::unique_lock<std::mutex> locker(work_event_.mu);
        work_event_.condition.wait(locker, [this] {
            return (exit_flag_ == true) || (wakeup_flag_ == true);
        });
        if (exit_flag_) {
            std::cout << "recv exit flag" << std::endl;
            break;
        }
        wakeup_flag_ = false;
        SampleStack();
    }
    is_running_ = false;
    std::cout << "thread terminate" << std::endl;
    exit_event_.condition.notify_one();
}

void ThreadModel::SampleStack() {
    static int i = 0;
    std::cout << "Sample Stack "  << ++i  << " " << exit_flag_ << std::endl;
}

}