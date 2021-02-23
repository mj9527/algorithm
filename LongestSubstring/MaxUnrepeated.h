//
// Created by mjzheng on 2020/5/20.
//

#ifndef ALGORITHM_MAXUNREPEATED_H
#define ALGORITHM_MAXUNREPEATED_H

#include <string>
#include <map>

using namespace std;

class MaxUnrepeated {
public:
    int lengthOfLongestSubstring(string s) {
        int c = s.size();
        int max = 0;
        int from = 0;
        map<char, int> a;
        for (int i=0; i<c; i++) {
            auto iter = a.find(s[i]);
            if (iter != a.end()) {
                if (max < i-from) {
                    max = i - from;
                }
                if (from < iter->second + 1) {
                    from = iter->second + 1;
                }
                iter->second = i;
                continue;
            }
            a.insert(std::make_pair(s[i], i));
        }
        if (max < c-from) {
            max = c-from;
        }
        return max;
    }
};

void TestUnrepeated() {
    MaxUnrepeated m;
//
//    string s1 = "abcabcbb";
//    int len1 = m.lengthOfLongestSubstring(s1); // 3
//    std::cout << len1 << std::endl;
//
//    string s2 = "bbbbb";
//    int len2 = m.lengthOfLongestSubstring(s2); // 1
//    std::cout << len2 << std::endl;

    string s3 = "abba";
    int len3 = m.lengthOfLongestSubstring(s3); // 2
    std::cout << len3 << std::endl;
}


#endif //ALGORITHM_MAXUNREPEATED_H
