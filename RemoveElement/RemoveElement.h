//
// Created by mjzheng on 2020/7/24.
//

#ifndef ALGORITHM_REMOVEELEMENT_H
#define ALGORITHM_REMOVEELEMENT_H

#include <vector>

using namespace std;


namespace RemoveElement {
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.empty()) {
                return 0;
            }
            int slow = 0;
            int n = nums.size();
            for (int i=0; i<n; i++) {
                if (nums[i] != val) {
                    nums[slow++] = nums[i];
                }
            }
            return slow;
        }
    };

    void TestRemove() {
        std::vector<int> nums{2,2,3,3};
        Solution r;
        int remain = r.removeElement(nums, 3);

        for (int i=0; i<remain;i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;

    }
}

#endif //ALGORITHM_REMOVEELEMENT_H
