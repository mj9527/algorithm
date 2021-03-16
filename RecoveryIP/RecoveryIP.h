//
// Created by 郑俊明 on 2020/4/18.
//

#ifndef ALGORITHM_RECOVERYIP_H
#define ALGORITHM_RECOVERYIP_H

#include <vector>
#include <string>
#include <iostream>

//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"]

using namespace std;


namespace RecoveryIP {

    class Solution {
    public:
//    vector<string> restoreIpAddresses(string s) {
//        vector<string> res;
//        for (int a = 1; a < 4; ++a)
//            for (int b = 1; b < 4; ++b)
//                for (int c = 1; c < 4; ++c)
//                    for (int d = 1; d < 4; ++d)
//                        if (a + b + c + d == s.size()) {
//                            int A = stoi(s.substr(0, a));
//                            int B = stoi(s.substr(a, b));
//                            int C = stoi(s.substr(a + b, c));
//                            int D = stoi(s.substr(a + b + c, d));
//                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
//                                string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
//                                if (t.size() == s.size() + 3) res.push_back(t);
//                            }
//                        }
//        return res;
//    }

        vector<string> restoreIpAddresses(string s) {
            string* p = new string[4];
            for (int i=0; i<4; i++) {
                p[i] = "";
            }

            vector<string> ls;
            backTracing(p, 0, 4, s, ls);
            return ls;
        }

        void backTracing(string* p, int row, int n, string s, vector<string>&ls) {
            //std::cout << s << std::endl;
            if (row == n) {
                if (s.empty()) {
                    ls.push_back(getIp(p, n));
                }
                //std::cout << getIp(p, n) << std::endl;
                return ;
            }

            for (int i=1; i<4&& i<=s.size(); i++) {
                std::string word = s.substr(0, i);
                if (isValid(word)) {
                    // std::cout << word << std::endl;
                    p[row] = word;
                    backTracing(p, row+1, n, s.substr(i), ls);
                    p[row] = "";
                }
            }
        }

        bool isValid(string& word) {
            int number = stoi(word);
            std::string tmp = to_string(number);
            if (number <= 255 && tmp == word) {
                return true;
            }
            return false;
        }

        string getIp(string* p, int n) {
            string ip("");
            for (int i=0; i<n; i++) {
                ip += p[i];
                if (i < n-1) {
                    ip +=".";
                }
            }
            return ip;
        }
    };

    void TestIP() {
        //string s = "25525511135";
        string s = "011255245";
        Solution recovery;
        vector<string> ipS = recovery.restoreIpAddresses(s);
        std::cout << "len " << ipS.size() << std::endl;
        for (vector<string>::iterator iter = ipS.begin(); iter != ipS.cend(); iter++) {
            std::cout << *iter << std::endl;
        }
    }
}

#endif //ALGORITHM_RECOVERYIP_H
