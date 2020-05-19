//
// Created by 郑俊明 on 2020/5/19.
//

#ifndef ALGORITHM_STRINGMULTI_H
#define ALGORITHM_STRINGMULTI_H

#include <iostream>
#include <string>

using namespace std;

class StringMultiple {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int total = l1 + l2;
        char* num3 = new char[total];
        for (int i=0; i<total; i++) {
            num3[i] = '0';
        }
        int a1 = 0;
        int a2 = 0;
        int sum = 0;
        for (int i=l1-1; i>=0; i--) {
            for (int j=l2-1; j>=0; j--) {
                sum = mul(num1[i], num2[j]);
                a1 = sum / 10;
                a2 = sum % 10;

                sum = num3[i+j+1] - '0' + a2;
                num3[i+j+1] = sum % 10 + '0';
                int bit = sum / 10;

                sum = num3[i+j] - '0' + a1 + bit;
                num3[i+j] = sum % 10 + '0';
                bit = sum / 10;
                if (bit > 0) {
                    num3[i+j-1] = num3[i+j-1] - '0' + bit + '0';
                }
                PrintA(num3, total);
            }
        }
        int from = 0;
        for (; from < total; from++) {
            if (num3[from] != '0') {
                break;
            }
        }

        string s(num3+from, num3+total);

        std::cout << s << std::endl;

        delete [] num3;
        return s;
    }

    int mul(char a, char b) {
        int a1 = a - '0';
        int b1 = b - '0';
        int sum = a1 * b1;
        //std::cout << a1 << " " << b1 << " " << sum << std:: endl;
        return sum;
    }

    void PrintA(char*p, int total) {
        for (int i=0; i<total; i++) {
             std::cout << p[i];
        }
        std::cout << std::endl;
    }

    void add (int a, int b, int&c, int& bit) {
        int sum = a + b;
        c = sum % 10;
        bit = sum /10;
    }

};


void TestMul() {
    string num1 = "999";
    string num2 = "999";
    StringMultiple s;
    s.multiply(num1, num2);
}

#endif //ALGORITHM_STRINGMULTI_H
