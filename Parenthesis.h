//
// Created by mjzheng on 2020/7/23.
//

#ifndef ALGORITHM_PARENTHESIS_H
#define ALGORITHM_PARENTHESIS_H

#include <vector>
#include <string>

class Parenthesis {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};

void TestParenthesis() {
    Parenthesis p;
    vector<string> s = p.generateParenthesis(3);
    //for (auto iter = s.begin(); iter != s.end() ; iter++) {
    for (auto i:s) {
        std::cout << i << std::endl;
    }
}


#endif //ALGORITHM_PARENTHESIS_H
