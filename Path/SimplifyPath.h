//
// Created by 郑俊明 on 2020/5/20.
//

#ifndef ALGORITHM_SIMPLIFYPATH_H
#define ALGORITHM_SIMPLIFYPATH_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SimplifyPath {
public:
    string simplifyPath(string path) {
        vector<string> v;
        SpiltString(path, "/", v);

        PrintVector(v);

        return Simple(v);
    }

    void SpiltString(string s, string split, vector<string>& v) {
        string::size_type pos1 = 0;
        string::size_type pos2 = s.find(split);
        string tmp;
        while (pos2 != string::npos) {
            tmp = s.substr(pos1, pos2-pos1);
            if (tmp!= ""){
                v.push_back(tmp);
            }
            pos1 = pos2 + split.size();
            pos2 = s.find(split, pos1);
        }
        if (pos1 != s.length()) {
            tmp = s.substr(pos1);
            if (tmp != "") {
                v.push_back(tmp);
            }
        }
    }

    string Simple(vector<string>& v) {
        vector<string> v1;
        //v1.push_back("/");

        for (auto& tmp :v) {
            if (tmp != "." && tmp != ".."){
                v1.push_back("/");
                v1.push_back(tmp);
                continue;
            }
            if (tmp == ".") {
                continue;
            }
            if (tmp == "..") {
                if (!v1.empty()) {
                    v1.pop_back();
                }
                if (!v1.empty()) {
                    v1.pop_back();
                }
            }
        }

        if (v1.empty()) {
            return "/";
        }
        std::string r;
        for (auto& tmp:v1) {
            r += tmp;
        }
        return r;
    }

    void PrintVector(vector<string>& v) {
        auto iter = v.begin();
        for (auto &iter:v) {
            std::cout << iter << "/" ;
        }
        std::cout << std::endl;
    }

};

void TestSimple() {
    SimplifyPath sp;
    string path = sp.simplifyPath("/a//b////c/d//././/..");

    std::cout << path << std::endl;

    string s1 = "/../";
    string s2 = sp.simplifyPath(s1);
    std::cout << "result " << s2 << std::endl;

}


#endif //ALGORITHM_SIMPLIFYPATH_H
