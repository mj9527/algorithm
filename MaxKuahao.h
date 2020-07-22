//
// Created by mjzheng on 2020/6/8.
//

#ifndef ALGORITHM_MAXKUAHAO_H
#define ALGORITHM_MAXKUAHAO_H

//#include <vector>
#include <stack>
#include <string>
#include <bitset>
#include <queue>

using namespace std;

class MaxKuahao {

};

int getMaxKuahao(std::string& s) {
    if (s.empty()) {
        return 0;
    }
    int n = s.size();
    stack<char> st;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            continue;
        }
    }
    return st.size();
}

struct TestPair{
    std::string s;
    int except;
    TestPair(std::string s1, int e) {
        s = s1;
        except = e;
    }
};

void TestQueue() {
    queue<int> q;
    for (int i=0; i<10; i++) {
        q.push(i);
    }

    for (int i=0; i<10; i++) {
        std::cout << q.front() << std::endl;
        q.pop();
    }
}

void TestPriotiyQueue() {
    priority_queue<int> q;
    for (int i=0; i<10; i++) {
        q.push(i);
    }

    for (int i=0; i<10; i++) {
        std::cout << q.top() << std::endl;
        q.pop();
    }
}


void TestKuahao() {
//    vector<TestPair> ls = {
//            {"()", 0},
//            {"(", 1},
//            {")", 1},
//            {"()(", 1},
//            {"((", 2},
//            {"))", 2},
//            {"()()", 0},
//            {"(())", 0},
//    };
//
//    auto iter = ls.begin();
//    for (; iter != ls.end(); iter++) {
//        int num = getMaxKuahao(iter->s);
//        if (num != iter->except) {
//            std::cout << "error " << iter->s << " " << iter->except << " " << num << std::endl;
//        } else {
//            std::cout << "ok " << iter->s << " " << iter->except << " " << num << std::endl;
//        }
//    }
//

//     bitset<8> bs;
//
//     for (int i=0; i<8; i++) {
//         if (i %2 == 0) {
//             bs.set(i, 1);
//         }
//     }
//
//     std::cout << bs.count() << std::endl;

     //TestQueue();
     TestPriotiyQueue();
}



#endif //ALGORITHM_MAXKUAHAO_H
