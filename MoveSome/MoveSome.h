//
// Created by 郑俊明 on 2020/5/16.
//

#ifndef ALGORITHM_MOVESOME_H
#define ALGORITHM_MOVESOME_H

#include <iostream>

using namespace std;

class MoveSome {
public:
    int* MoveLen(int* origin, int n, int i) {
        std::cout << origin << " " << n << " " << i << std::endl;
        if (i >= n || i <=0) {
            OutArrray(origin, n);
            return nullptr;
        }

//        int remain = n-i-1;
//        if (i <= remain) {
//            int left = n;
//            while (left > 0) {
//                SwapSome(origin, left, i);
//                left = left -i;
//            }
////            SwapSome(origin, n, i);
////            SwapSome(origin, n-i, i);
//        } else {
//            //SwapSome(origin, n, remain);
//            //SwapSome(origin+remain, n-remain, remain);
//        }
        Reverse(origin, 0, i-1);
        Reverse(origin, i, n-1);
        Reverse(origin, 0, n-1);

        OutArrray(origin, n);

        return nullptr;
    }

    void OutArrray(int*origin, int n) {
        for (int i=0; i<n; i++) {
            std::cout << origin[i] << " ";
        }
        std::cout << std::endl;
    }


    int* SwapSome(int* origin, int n, int i) {
        int k = n-1;
        for (int j=i-1; j>=0; j--) {
            if (j == k) {
                continue;
            }
            std::swap(origin[j], origin[k]);
            k--;
        }
    }

    int Reverse(int* origin, int from, int to) {
        int l = from;
        int r = to;
        while (l < r) {
            std::swap(origin[l], origin[r]);
            l++;
            r--;
        }
    }
};


void TestMoveSome() {
    int origin[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MoveSome m;
    m.MoveLen(origin, sizeof(origin) / sizeof(int), 0);
}


#endif //ALGORITHM_MOVESOME_H
