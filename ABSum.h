//
// Created by mjzheng on 2020/6/4.
//

#ifndef ALGORITHM_ABSUM_H
#define ALGORITHM_ABSUM_H

#include <vector>
#include <map>
#include "algorithm"

using namespace std;

class ABSum {

};

void TestABSum() {
    vector<int> a = {1, 4, 5};
    vector<int> b = {3, 4, 6};
    int sum = 8;

    map<int, int> aIndex;
    int aLen = a.size();
    for (int i=0; i<aLen; i++) {
        aIndex.insert(std::make_pair(sum-a[i],i));
        //std::cout << "insert " << sum-a[i] << " " << i << std::endl;
    }

    int bLen = b.size();
    for (int j=0; j<bLen; j++) {
        int remain = b[j];
       // std::cout << remain << std::endl;
        auto iter = aIndex.find(remain);
        if (iter != aIndex.end()) {
            std::cout << j << " " << iter->second << std::endl;
        }
    }

}

void TestKNum() {
    vector<int> a = {4, 1, 3, 2, 7, 9, 8, 10, 12};
    int n = a.size();
    int leftMax = INT_MIN;
    set<int> b;
    for (int i=0; i<n; i++) {
        if (a[i] > leftMax) {
            if (i != 0) {
                b.insert(a[i]);
            }
            leftMax = a[i];
        }
    }
    int rightMin = INT_MAX;
    set<int> c;
    for (int i=n-1; i>=0; i--) {
        if (a[i] < rightMin) {
            if (i != n-1) {
                c.insert(a[i]);
            }
            rightMin = a[i];
        }
    }

    set<int> d;
    set_intersection(b.begin(), b.end(), c.begin(), c.end(), inserter( d, d.begin() ));
    auto iter = d.begin();
    for (; iter != d.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}



#endif //ALGORITHM_ABSUM_H
