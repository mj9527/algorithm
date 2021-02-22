//
// Created by mjzheng on 2021/2/22.
//

#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H

#include <map>
#include <vector>

using namespace std;

namespace TwoSum {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            std::vector<int> result;
            int size = nums.size();
            std::map<int, int> flag;
            for (int i=0; i<size; i++) {
                std::map<int, int>::iterator iter = flag.find(nums[i]);
                if (iter != flag.end()) {
                    result.push_back(i);
                    result.push_back(iter->second);
                    return result;
                }
                flag.insert(std::make_pair(target-nums[i], i));
            }
            return result;
        }
    };

    void testTwoSum() {
        vector<int> nums = {2, 7, 11, 15};
        int sum = 9;
        Solution s;
        s.twoSum(nums, 9);
    }
}


#endif //ALGORITHM_TWOSUM_H
