//
// Created by mjzheng on 2021/2/23.
//

#ifndef ALGORITHM_MAXAREA_H
#define ALGORITHM_MAXAREA_H


#include <vector>
#include <iostream>

using namespace std;

namespace MaxArea {
    class Solution {
    public:
        int maxArea(vector<int>& height) {
            if(height.size() <= 1) return -1;
            int i = 0, j = height.size() - 1, res = 0;
            while(i < j){
                int h = min(height[i], height[j]);
                res = max(res, h * (j - i));
                if(height[i] < height[j]) ++i;
                else --j;
            }
            return res;
        }
    };

    void testMaxArea() {
        Solution s;
        vector<int> height = {1,8,6,2,5,4,8,3,7};
        int area = s.maxArea(height);
        if (area == 49) {
            std::cout << "right" << std::endl;
        } else {
            std::cout << "error" << std::endl;
        }
    }
}

#endif //ALGORITHM_MAXAREA_H
