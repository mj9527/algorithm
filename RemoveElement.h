//
// Created by mjzheng on 2020/7/24.
//

#ifndef ALGORITHM_REMOVEELEMENT_H
#define ALGORITHM_REMOVEELEMENT_H

#include <vector>

using namespace std;


class RemoveElement {
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

//        int remaind = 0;
//        int n = nums.size();
//        if (n==0) {
//            return 0;
//        }
//        int lastIndex = n-1;
//        for (int i=n-1; i>=0; i--) {
//            if (nums[i] == val) {
//                while (nums[lastIndex] == val && lastIndex>0) {
//                    lastIndex--;
//                }
//                if (lastIndex >= 0 && lastIndex > i) {
//                    std::swap(nums[i], nums[lastIndex]);
//                }
//            } else {
//                remaind++;
//            }
//        }
//        return remaind;
    }
};

void TestRemove() {
    std::vector<int> nums{2,2,3,3};
    RemoveElement r;
    int remain = r.removeElement(nums, 3);

    for (int i=0; i<remain;i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

}


#endif //ALGORITHM_REMOVEELEMENT_H
