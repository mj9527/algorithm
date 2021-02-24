//
// Created by mjzheng on 2021/2/24.
//

#ifndef ALGORITHM_LONGESTCOMMONPREFIX_H
#define ALGORITHM_LONGESTCOMMONPREFIX_H

namespace LogestCommonPrefix {
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";
            }
            return longestPrefix(strs, 0, strs.size());
        }

        // no include to position
        string longestPrefix(vector<string>& strs, int from, int to) {
            if (to-from ==1) {
                return strs[from];
            }
            int m = (from + to)/2;
            string s1 = longestPrefix(strs, from, m);
            string s2 = longestPrefix(strs, m, to);
            string s3 = mergePrefix(s1, s2);
            return s3;
        }

        string mergePrefix(string s1, string s2) {
            int l1 = s1.size();
            int l2 = s2.size();
            int min = l1<l2 ? l1:l2;
            int i=0;
            for (;i<min; i++) {
                if (s1[i] != s2[i]) {
                    break;
                }
            }
            return s1.substr(0, i);
        }
    };
}

#endif //ALGORITHM_LONGESTCOMMONPREFIX_H
