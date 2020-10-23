//
// Created by mjzheng on 2020/8/18.
//

#ifndef ALGORITHM_GROUPANAGRAMS_H
#define ALGORITHM_GROUPANAGRAMS_H

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> groups;
        for (auto& str : strs)
        {
            std::string original = str;
            std::sort(str.begin(), str.end());
            std::cout << str << std::endl;
            auto iter = groups.find(str);
            if (iter != groups.end())
            {
                iter->second.push_back(original);
            }
            else
            {
                std::vector<std::string> ls;
                ls.push_back(original);
                groups.insert(std::make_pair(str, ls));
            }
        }
        vector<vector<string>> result;
        for (auto& item : groups)
        {
            result.push_back(item.second);
        }
        return result;
    }
};

void TestGroupAnagrams()
{
    std::vector<std::string> samples = {"eat", "tea", "tan", "ate", "nat", "bat"};
    GroupAnagrams a;
    auto result = a.groupAnagrams(samples);
    for (auto& item : result) {
        for (auto& word : item) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

#endif //ALGORITHM_GROUPANAGRAMS_H
