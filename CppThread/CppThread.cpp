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

}

ThreadModel::~ThreadModel() {

}

int ThreadModel::StartThread() {
    exit_flag_ = false;
    is_running_ = true;
    std::thread th(&ThreadModel::Run, this);
    th.detach();
    return 0;
}

int ThreadModel::StopThread() {
    std::cout << "start stop thread" << std::endl;

    exit_flag_ = true;
    work_event_.notify_one();
    std::unique_lock<std::mutex> locker(exit_mutex_);
    exit_event_.wait(locker, [this] {
        return !is_running_;
    });

    std::cout << "finish stop thread" << std::endl;
    return 0;
}

int ThreadModel::WakeupThread() {
    wakeup_flag_ = true;
    work_event_.notify_one();
}

void ThreadModel::Run() {
    is_running_ = true;
    while (!exit_flag_) {
        std::unique_lock<std::mutex> locker(work_mutex_);
        work_event_.wait(locker, [this] {
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
    exit_event_.notify_one();
}

void ThreadModel::SampleStack() {
    static int i = 0;
    std::cout << "Sample Stack "  << ++i  << " " << exit_flag_ << std::endl;
}

}