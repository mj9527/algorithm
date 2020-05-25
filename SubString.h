//
// Created by mjzheng on 2020/5/20.
//

#ifndef ALGORITHM_SUBSTRING_H
#define ALGORITHM_SUBSTRING_H

#include <iostream>
#include <string>

using namespace std;


// kmp algorithm
int IndexWithKMP(string s, string t) {
    return 0;
}


// normal
int Index(string s, string t) {
    int i = 0;
    int l1 = s.size();
    int j = 0;
    int l2 = t.size();
    while (i<l1 && j<l2) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i++;
            j=0;
        }
    }
    std::cout << i << " " << j << std::endl;
    if (j >= l2) {
        return i-l2;
    }
    return 0;
}

void TestSubString() {

    string s1 = "abcdefg";
    string child = "cde";
    int index = Index(s1, child);
    std::cout << index << std::endl;
}


#endif //ALGORITHM_SUBSTRING_H
