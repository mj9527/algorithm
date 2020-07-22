//
// Created by mjzheng on 2020/6/3.
//

#ifndef ALGORITHM_STOCK_H
#define ALGORITHM_STOCK_H

#include <iostream>
#include <limits.h>

class Stock {

};

void PrintAA(int**p, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << p[i][j];
        }
        std::cout << std::endl;
    }
}

int64_t GetMaxReward(int64_t**p, int n) {
    int64_t sum = 0;
    int64_t crossMin = INT_MAX;
    int64_t otherMax = INT_MIN;
    int64_t crossMax = INT_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sum += 2*p[i][j];
            if (i == j || i+j == n-1) {
                if (p[i][j] < crossMin) {
                    crossMin = p[i][j];
                }
                if (p[i][j] > crossMax) {
                    crossMax = p[i][j];
                }
                sum += p[i][j];
                if (i==j && i+j==n-1) {
                    sum += p[i][j];
                }
            } else {
                if (p[i][j] > otherMax) {
                    otherMax = p[i][j];
                }
            }
        }
    }

    if (n % 2 == 1) { // 奇数
        int64_t max = 0;
        if (otherMax > crossMin) {
            int delta = otherMax - crossMin;
            int delta2 = 2*(otherMax - p[n/2][n/2]);
            max = delta > delta2 ? delta : delta2;
        }
        if (crossMax > p[n/2][n/2]) {
            int delta3 = crossMax - p[n/2][n/2];
            if (delta3 > max) {
                max = delta3;
            }
        }
        sum += max;
    } else { // 偶数
        if (otherMax > crossMin) {
            sum += otherMax - crossMin;
        }
    }
    //std::cout << sum << std::endl;
    return sum;
}

int TestStock() {
    int t = 0;
    std::cin >> t;

    int* result = new int[t];
    for (int i=0; i<t; i++) {
        int n = 0;
        std::cin >> n;
        int64_t ** p = new int64_t*[n];
        for (int j=0; j<n; j++) {
            p[j] = new int64_t[n];
            for (int k=0; k<n; k++) {
                std::cin >> p[j][k];
            }
        }

        result[i]=GetMaxReward(p, n);

        //PrintAA(p, n);
    }
    for (int i=0; i<t; i++) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}


#endif //ALGORITHM_STOCK_H
