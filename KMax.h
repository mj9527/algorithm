//
// Created by 郑俊明 on 2020/4/29.
//

#ifndef ALGORITHM_KMAX_H
#define ALGORITHM_KMAX_H

#include <vector>

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

class KMax {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), cmp);
        vector<int>::iterator iter = nums.begin();
//        for (; iter != nums.end(); iter++) {
//            std::cout << *iter << std::endl;
//        }

//        if (k <= nums.size()) {
//            return nums[nums.size() -k];
//        }
         return nums[k-1];
    }
};

void TestFindK() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    KMax k;
    int result = k.findKthLargest(nums, 4);
    std::cout << result << std::endl;
}

#endif //ALGORITHM_KMAX_H
