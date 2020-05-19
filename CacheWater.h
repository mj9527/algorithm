//
// Created by 郑俊明 on 2020/4/19.
//

#ifndef ALGORITHM_CACHEWATER_H
#define ALGORITHM_CACHEWATER_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class CacheWater {
public:
    int trap(vector<int>& height) {
        int from = 0;
        int to = 0;
        int total = 0;
        int count = height.size();
        for (int i=1; i<count; i++) {
            to = i;

            if (height[i] >= height[from]) {
                total += calcBucket(height, from, to);
                from = to;
                continue;
            }
        }

        if (from < to) {
            //std::cout << "last " << from << " " << to << std::endl;
            vector<int> child = getChild(height, from, to);
            total += trap(child);
        }
        return total;
    }

    int calcBucket(vector<int>& height, int from, int to) {
        //std::cout << "before range " << from << " " << to << std::endl;
        if (from + 1 == to) {
            return 0;
        }
        //std::cout << "range " << from << " " << to << std::endl;
        int min = std::min(height[from], height[to]);
        int container = min * (to - from + 1);
        int occupation = 0;
        for (int i = from; i<=to; i++) {
            int h = height[i];
            if (h > min) {
                h = min;
            }
            occupation += h * 1;
        }
        if (container < occupation) {
            std::cout << "unexception"  << std::endl;
            return 0;
        }
        return container - occupation;
    }

    vector<int> getChild(vector<int>& height, int from, int to) {
        vector<int> child;
        for (int i = to; i>=from; i--) {
            child.push_back(height[i]);
        }
        return child;
    }

};

void TestWater() {
    vector<int> intervals = {0,1,0,2,1,0,1,3,2,1,2,1};
    //vector<int> intervals = {3,2,1,2,1};
    CacheWater w;
    int total = w.trap(intervals);
    std::cout << "water " << total << std::endl;
}

#endif //ALGORITHM_CACHEWATER_H
