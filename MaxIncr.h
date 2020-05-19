//
// Created by 郑俊明 on 2020/5/12.
//

#ifndef ALGORITHM_MAXINCR_H
#define ALGORITHM_MAXINCR_H

#include <vector>
#include <iostream>

using namespace std;

class MaxIncr {
public:
    int findLengthOfLCIS(vector<int>& nums) {
//        int max = 0;
////        int len = nums.size();
////        int count = 1;
////        for (int i=1; i<len; i++) {
////            if (nums[i] > nums[i-1]) {
////                count++;
////            } else {
////                if (count > max) {
////                    max = count;
////                }
////                count =1;
////            }
////        }
////        return max;
         int maxsofar = INT_MIN;
         int maxendinghere = 0;
         int len = nums.size();
         for (int i=0; i<len; i++) {
             maxendinghere = max(maxendinghere + nums[i], nums[i]);
             maxsofar = max(maxsofar, maxendinghere);
         }
         return maxsofar;
    }
};

void TestIncr() {
    vector<int> nums ={1,3,5,4,7};
    MaxIncr m;
    int max = m.findLengthOfLCIS(nums);
    std::cout << max << std::endl;
}


#endif //ALGORITHM_MAXINCR_H
