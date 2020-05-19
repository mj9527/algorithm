//
// Created by 郑俊明 on 2020/4/25.
//

#ifndef ALGORITHM_REVERSEWORD_H
#define ALGORITHM_REVERSEWORD_H

#include <iostream>
#include <vector>

class ReverseWord {
public:
    string reverseWords(string s) {
       int from = 0;
       vector<string> words;
       size_t len = s.size();
       for (int i=0; i<len; ) {
           while (i<len && s[i] == ' ') ++i; // erase front empty
           if (i==len) {
               break;
           }
           from = i;
           while (i<len && s[i] != ' ') ++i; // find all string
           string word = s.substr(from, i-from);
           words.push_back(word);
           std::cout << word  <<std::endl;
       }

       //std::cout << words.size() << std::endl;

       string result = "";
       for (int j= words.size()-1; j>=0; j--) {
           //std::cout << words[j] << std::endl;
           result += words[j];
           if (j != 0) {
               result += " ";
           }

       }
       return result;
    }
};

void TestReverse() {
    ReverseWord r;
    //string result = r.reverseWords("   hello   world   ");
    string result = r.reverseWords("the sky is blue");
    std::cout << result << std::endl;

}


#endif //ALGORITHM_REVERSEWORD_H
