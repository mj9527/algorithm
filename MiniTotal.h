//
// Created by 郑俊明 on 2020/4/25.
//

#ifndef ALGORITHM_MINITOTAL_H
#define ALGORITHM_MINITOTAL_H

#include <vector>

using namespace std;

class MiniTotal {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


#endif //ALGORITHM_MINITOTAL_H
