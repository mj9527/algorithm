//
// Created by 郑俊明 on 2020/4/19.
//

#ifndef ALGORITHM_ENVELOPES_H
#define ALGORITHM_ENVELOPES_H

void PrintArray(vector<vector<int>>& result) {
    vector<vector<int>>::iterator iter = result.begin();
    for (; iter != result.end(); iter++) {
        for (vector<int>::iterator e = iter->begin(); e != iter->end(); e++) {
            std::cout << *e << " ";
        }
        std::cout << std::endl;
    }
}

bool comp_coor(const vector<int> &c1,const vector<int> &c2){
    if (c1[0] > c2[0]) {
        return false; // up
    } else if (c1[0] == c2[0]) {
        if (c1[1] > c2[1]) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

class Envelopes {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), comp_coor);
        PrintArray(envelopes);
        std::cout << "start ..." << std::endl;
        int sum  = 0;
        int len = envelopes.size();
        int *dp = new int[len];
        dp[0] = 1;
        for (int i=1; i<len; i++) {
            dp[i] = 1;
            for (int j=0; j<i; j++) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            std::cout << " dp " << dp[i] << std::endl;
            if (sum < dp[i]) {
                sum = dp[i];
            }
        }
        return sum;
    }

};

void TestEnvelopes() {
    //vector<vector<int>> envelopes = {{5,4},{6,7}, {6,4},{2,3},{7,6}, {8,7}};
    //vector<vector<int>> envelopes = {{5,4},{6,7}, {6,4},{2,3}};
    //vector<vector<int>> envelopes = {{30,50},{12,2},{3,4},{12,15}};
   // vector<vector<int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    vector<vector<int>> envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};
    Envelopes e;
    int sum = e.maxEnvelopes(envelopes);
    std::cout << sum << std::endl;

    int a = 1;
    int b = 2;
    if (a && b) {

    }
}


#endif //ALGORITHM_ENVELOPES_H
