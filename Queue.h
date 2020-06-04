//
// Created by 郑俊明 on 2020/5/27.
//

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H


class NQueue {
public:
    vector<vector<string>> solveNQueens(int n) {
        char** p = new char*[n];
        for (int i=0; i<n; i++) {
            p[i] = new char[n];
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                p[i][j] = '.';
            }
            //std::cout << std::endl;
        }

        vector<vector<string>> s;
        backTracing(p, 0, n, s);
        return s;
    }

    void backTracing(char**p, int row, int n, vector<vector<string>>&s) {
        if (n == row) {
            // find one
            s.push_back(chsToList(p, n));
            return ;
        }

        for (int col=0; col<n; col++) {
            if (isValid(p, row, col, n)) {
                p[row][col] = 'Q';
                backTracing(p, row+1, n, s);
                p[row][col] = '.';
            }
        }

    }
    vector<string> chsToList(char** p, int n ) {
        vector<string> one;
        for (int i=0; i<n; i++) {
            one.push_back(string(p[i], n));
        }
        return one;
    }

    bool isValid(char**p, int x, int y, int n) {
        for(int i=0;i<=x;i++){
            for(int j=0;j<n;j++){
                if(p[i][j]=='Q'&&(j==y||abs(x-i)==abs(y-j))){
                    return false;
                }
            }
        }
        return true;
    }


};

void PrintV(vector<vector<string>>& s) {
    auto iter = s.begin();
    for (; iter != s.end(); iter++) {
        auto j = iter->begin();
        for (; j != iter->end(); j++) {
            std::cout << *j << std::endl;
        }
        std::cout << std::endl;
    }
}

void TestQueue() {
    NQueue q;
    vector<vector<string>> s = q.solveNQueens(4);
    PrintV(s);
}


#endif //ALGORITHM_QUEUE_H
