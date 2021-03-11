//
// Created by mjzheng on 2021/3/9.
//

#ifndef ALGORITHM_ADDTWOBIGNUMBER_H
#define ALGORITHM_ADDTWOBIGNUMBER_H

#include <string>
#include <vector>

namespace AddTwoBigNumber {
    class Solution {
    public:
        std::string bigNumberAdd(std::string& num1, std::string& num2) {
            if (num1.empty()) {
                return num2;
            }
            if (num2.empty()) {
                return num1;
            }
            std::cout << num1 << " " << num2 << std::endl;
            int bit = 0;
            int sum = 0;
            int over = 0;
            std::string result;
            int i = num1.size() -1;
            int j = num2.size() -1;
            while (i>=0||j>=0) {
                sum = getInt(i, num1) + getInt(j, num2) + over;
                bit = sum % 10;
                over = sum / 10;
                result.push_back(toChar(bit));
                --i;
                --j;
            }

            if (over > 0) {
                result.push_back(toChar(over));
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

        inline char toChar(int bit) {
            return (bit + '0');
        }

        inline int getInt(int index, std::string& num) {
            if (index >= 0) {
                return (num[index] - '0');
            }
            return 0;
        }
    };



    void testAddTwoBigNumber() {
        std::string num1 = "9999999898";
        std::string num2 = "6789";
        std::string target = "10000006687";
        Solution s;
        std::string result = s.bigNumberAdd(num1, num2);

        if (target != result) {
            std::cout << "error " << target << " " << result << std::endl;
        } else {
            std::cout << "right " << result << std::endl;
        }
    }
}


// 前缀形式：
int& int::operator++() //这里返回的是一个引用形式，就是说函数返回值也可以作为一个左值使用
{//函数本身无参，意味着是在自身空间内增加1的
    *this += 1;  // 增加
    return *this;  // 取回值
}

//后缀形式:
const int int::operator++(int) //函数返回值是一个非左值型的，与前缀形式的差别所在。
{//函数带参，说明有另外的空间开辟
    int oldValue = *this;  // 取回值
    ++(*this);  // 增加
    return oldValue;  // 返回被取回的值
}

#endif //ALGORITHM_ADDTWOBIGNUMBER_H
