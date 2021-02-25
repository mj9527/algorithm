//
// Created by mjzheng on 2021/2/24.
//

#ifndef ALGORITHM_VALIDPARENTHESIS_H
#define ALGORITHM_VALIDPARENTHESIS_H

namespace ValidParenthesis {
#include <stack>

    class Solution {
    public:
        bool isValid(string s) {
            if (s.empty()) {
                return true;
            }
            stack<char> st;
            int n = s.size();
            for (int i=0; i<n; i++) {
                if (s[i] == '(' || s[i]=='{' || s[i] == '[') {
                    st.push(s[i]);
                } else {
                    if (st.size() > 0) {
                        char top = st.top();
                        if ( (top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') ||
                             (top == '[' && s[i] == ']') ){
                            st.pop();
                        } else {
                            st.push(s[i]);
                        }
                    } else {
                        st.push(s[i]);
                    }
                }
            }
            return st.size() == 0 ? true : false;
        }
    };
}
#endif //ALGORITHM_VALIDPARENTHESIS_H
