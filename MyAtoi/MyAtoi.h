//
// Created by mjzheng on 2021/2/23.
//

#ifndef ALGORITHM_MYATOI_H
#define ALGORITHM_MYATOI_H

#include <string>
#include <iostream>

using namespace std;

namespace MyAtoi {
    class Solution {
    public:
        int myAtoi(string str) {
            int j = getFirstChar(str);
            if (j == -1) {
                return 0;
            }
            int bNegative = 1;
            char c = str[j];
            size_t len = str.length();
            if (c == '-') {
                bNegative = -1;
                ++j;
            } else if (c == '+') {
                ++j;
            }

            long real = 0;
            for (; j<len; j++) {
                c = str[j];
                if (c < '0' || c > '9') {
                    break;
                }
                real = real * 10 + (c - '0');
                if (real >= 2147483648) {
                    return (bNegative == -1)? INT_MIN : INT_MAX;
                }
            }
            return real *bNegative;
        }

        int getFirstChar(string str) {
            size_t len = str.length();
            for (int i=0; i<len; i++) {
                char c = str[i];
                if (c != ' ') {
                    return i;
                }
            }
            return -1;
        }
    };

    void testMyAtoi() {
        std::string s = "4193 with words";
        Solution solution;
        int result = solution.myAtoi(s);
        std::cout << result << std::endl;
    }
}

#endif //ALGORITHM_MYATOI_H
