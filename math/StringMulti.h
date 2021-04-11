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
        auto l1 = num1.size();
        auto l2 = num2.size();
        auto l3 = l1 + l2;
        int* num3 = new int[l3]{0};
        auto print = [=] {
            return;
            for (int i=0; i<l3; i++) {
                std::cout << num3[i] << " ";
            }
            std::cout << std::endl;
        };
        print();

        for (int i=l1-1; i>=0; i--) {
            for (int j=l2-1; j>=0; j--) {
                int sum = mul(num1[i], num2[j]);
                auto bit = addBit(num3[i+j+1], sum);
                int k = 0;
                while (bit > 0) {
                    bit = addBit(num3[i+j-k], bit);
                    k++;
                }
                print();
            }
        }

        char* result = new char[l3];
        bool bStart = false;
        int k =0;
        for (int i=0; i<l3; i++) {
            if (num3[i] > 0) {
                bStart = true;
            }
            if (bStart) {
                result[k++] = (num3[i]+'0');
            }
        }
        std::string str(result, k);

        std::cout << str << std::endl;
        return "";

        delete [] num3;
    }

    int addBit(int& a1, const int a2) {
        auto sum = a1 + a2;
        a1 = sum % 10;
        auto bit = sum /10;
        return bit;
    }

    int mul(char a, char b) {
        int a1 = a - '0';
        int b1 = b - '0';
        int sum = a1 * b1;
        return sum;
    }
};


void TestMul() {
    string num1 = "999";
    string num2 = "999";
    StringMultiple s;
    s.multiply(num1, num2);
}

#endif //ALGORITHM_STRINGMULTI_H
