//
// Created by 郑俊明 on 2020/5/20.
//

#ifndef ALGORITHM_MINSTACK_H
#define ALGORITHM_MINSTACK_H

#include <stack>

namespace StackUtils {
    class MinStack {
    public:
        MinStack() {

        }

        void push(int x) {
            s.push(x);
            if (min.empty() || x <= min.top()) {
                min.push(x);
            }
        }

        void pop() {
            if (s.top() == min.top()) {
                min.pop();
            }
            s.pop();
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return min.top();
        }

    private:
        std::stack<int> s;
        std::stack<int> min;
    };

    void TestMinStack() {
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
}



#endif //ALGORITHM_MINSTACK_H
