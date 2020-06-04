//
// Created by 郑俊明 on 2020/5/20.
//

#ifndef ALGORITHM_MINSTACK_H
#define ALGORITHM_MINSTACK_H

#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MIN;
    }

    void push(int x) {
        s.push_back(x);
        if (min.empty()) {
            min.push_back(x);
        } else if (x < min.back()) {
            min.push_back(x);
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.back() == min.back()) {
                min.pop_back();
            }
            s.pop_back();
        }

    }

    int top() {
        return s.back();
    }

    int getMin() {
        return min.back();
    }

private:
    vector<int> s;
    vector<int> min;
};

void TestMin() {
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    obj->getMin();
    obj->pop();
    obj->getMin();
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}


#endif //ALGORITHM_MINSTACK_H
