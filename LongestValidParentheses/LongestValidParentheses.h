//
// Created by mjzheng on 2021/3/4.
//

#ifndef ALGORITHM_LONGESTVALIDPARENTHESES_H
#define ALGORITHM_LONGESTVALIDPARENTHESES_H

#include <stack>
#include <string>
#include <iostream>

using namespace std;

namespace LongestValidParentheses {
    struct CharFlag {
        char a;
        int index;
        CharFlag(char tmp, int pos) {
            a = tmp;
            index = pos;
        }
    };

    class Solution {
    public:
        int longestValidParentheses(string s) {
            if (s.empty()) {
                return 0;
            }
            stack<CharFlag> st;
            int n = s.size();
            //std::cout << n << std::endl;
            int *p = new int[n];
            for (int i=0; i<n; i++) {
                p[i] = 0;
                if (s[i] == '(') {
                    CharFlag flag(s[i], i);
                    st.push(flag);
                } else {
                    if (!st.empty() && st.top().a == '(') {
                        p[st.top().index] = 1;
                        p[i] = 1;
                        st.pop();
                    } else {
                        CharFlag flag(s[i], i);
                        st.push(flag);
                    }
                }
            }
            int current = 0;
            int max = 0;
            for (int i=0; i<n; i++) {
                //std::cout << p[i] << std::endl;
                if (p[i]==0) {
                    if (current > max) {
                        max = current;
                    }
                    current = 0;
                } else {
                    current++;
                }
            }
            if (current > max) {
                max = current;
            }
            return max;
        }
    };

    void testLongestValidParentheses() {
        Solution s;
        std::string parentheses = ")()(";
        int result = s.longestValidParentheses(parentheses);
        std::cout << result << std::endl;
    }
}

#endif //ALGORITHM_LONGESTVALIDPARENTHESES_H
