//
// Created by 郑俊明 on 2020/5/19.
//

#ifndef ALGORITHM_MAXUNREPEATE_H
#define ALGORITHM_MAXUNREPEATE_H

#include <set>
#include <iostream>
#include <map>

using namespace std;

class MaxUnrepeate {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        return longest(s, 0, s.size());
    }

    int longest(string s, int from, int to) {
        if (to -from == 1) {
            return 1;
        }
        int m = (from + to) / 2;
        int max1 = longest(s, from, m);
        int max2 = longest(s, m, to);
        int max3 = midest(s, from, to, m);

        return max(max(max1, max2), max3);
    }

    int midest(string s, int from, int to, int m) {
        std::set<char> a;

        for (int i=m; i>=from; i--) {
            if (a.count(s[i]) != 0) {
                break;
            }
            a.insert(s[i]);
        }
        for (int j=m+1; j<to; j++) {
            if (a.count(s[j]) != 0) {
                break;
            }
            a.insert(s[j]);
        }
        int max1 = a.size();

        a.clear();
        for (int j=m+1; j<to; j++) {
            if (a.count(s[j]) != 0) {
                break;
            }
            a.insert(s[j]);
        }

        for (int i=m; i>=from; i--) {
            if (a.count(s[i]) != 0) {
                break;
            }
            a.insert(s[i]);
        }
        int max2 = a.size();


        return max(max1, max2);
    }
};

void TestUnrepeate() {
   // string s = "abcb";
    string s = "bziuwnklhqzrxnb";
    MaxUnrepeate m;
    std::cout << m.lengthOfLongestSubstring(s) << std::endl;
}


#endif //ALGORITHM_MAXUNREPEATE_H
