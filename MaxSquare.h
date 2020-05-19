//
// Created by 郑俊明 on 2020/4/19.
//

#ifndef ALGORITHM_MAXSQUARE_H
#define ALGORITHM_MAXSQUARE_H

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> TransferSquare(vector<vector<char>>& matrix) {
    vector<vector<char>>::iterator row = matrix.begin();
    vector<vector<int>> result;
    for (; row != matrix.end(); row++) {
        vector<char>::iterator column = row->begin();
        vector<int> c;
        for (; column != row->end(); column++) {
            int b = *column - '0';
            std::cout << b << " ";
            c.push_back(b);
        }
        std::cout << std::endl;
        result.push_back(c);
    }
    return result;
}

class MaxSquare {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> f = TransferSquare(matrix);
        int rowLen = f.size();
        int columnLen = f[0].size();
        int ans = 0;
        for (int i=1; i<rowLen; i++) {
            for (int j=1; j<columnLen; j++) {
                if (f[i][j] == 1) {
                    f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
                    std::cout << "f " << f[i][j] <<std::endl;
                    ans=max(ans,f[i][j]);
                }

            }
        }
        return ans* ans;

    }
};

void TestSquare() {
    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','1','1','1','1'}};
    MaxSquare s;
    int len = s.maximalSquare(matrix);

    std::cout << "max length " << len << std::endl;
}

void PrintSquare(vector<vector<char>>& matrix) {
    vector<vector<char>>::iterator row = matrix.begin();
    for (; row != matrix.end(); row++) {
        vector<char>::iterator column = row->begin();

        for (; column != row->end(); column++) {
            std::cout << *column << " ";
        }
        std::cout << std::endl;
    }
}


#endif //ALGORITHM_MAXSQUARE_H
