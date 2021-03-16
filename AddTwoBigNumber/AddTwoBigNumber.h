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

    struct NumberPair {
        std::string num1;
        std::string num2;
        std::string target;
    };

    void testAddTwoBigNumber() {
        std::string num1 = "9999999898";
        std::string num2 = "6789";
        std::string target = "10000006687";

        std::vector<NumberPair> testList = {{"9999999898", "6789", "10000006687"}, {"9999", "1", "10000"}};
        for (auto& item : testList) {
            Solution s;
            std::string result = s.bigNumberAdd(item.num1, item.num2);
            if (item.target != result) {
                std::cout << "error " << target << " " << result << std::endl;
            } else {
                std::cout << "right " << result << std::endl;
            }
        }
    }
}


#endif //ALGORITHM_ADDTWOBIGNUMBER_H
