//
// Created by 郑俊明 on 2020/4/27.
//

#ifndef ALGORITHM_ROTATESEARCH_H
#define ALGORITHM_ROTATESEARCH_H

#include <vector>

using namespace std;

namespace RotateSearch {
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int minIndex = findMin(nums);
            //std::cout << "min index " << minIndex << std::endl;
            if (minIndex >=1) {
                int index = binaryFind(nums, 0, minIndex-1, target);
                if (index >=0) {
                    return index;
                }
            }
            return binaryFind(nums, minIndex, nums.size()-1, target);
        }

        int findMin(vector<int>& nums) {
            int left = 0;
            int right = nums.size()-1;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                // std::cout << left << mid << right << std::endl;
                if ((mid == 0 || nums[mid] < nums[mid-1]) && (mid==nums.size()-1 || nums[mid] < nums[mid+1])) {
                    break;
                }
                if (nums[mid] >= nums[0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (nums[0] < nums[mid]) {
                return 0;
            }
            return mid;
        }

        int findMin2(vector<int>& nums) {
            size_t len = nums.size();
            if (len == 0) {
                return 0;
            }
            size_t left = 0;
            size_t right = len -1;
            size_t mid = 0;
            while (left <= right) {
                mid = (left + right) /2;
                if ((mid == 0 || nums[mid] < nums[mid-1]) && (mid==len-1 || nums[mid] < nums[mid+1])) {
                    break;
                }

                // mid 不可能是最小值
                if (nums[mid] > nums[0]) {
                    left = mid + 1;
                } else {
                    right = mid -1;
                }
            }
            if (nums[0] < nums[mid]) {
                return nums[0];
            }
            return nums[mid];
        }

        int binaryFind(vector<int> nums, int from, int to, int target) {
            int left = from;
            int right = to;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        }

    };

    void TestSearch() {
        //vector<int> nums= {4,5,6,7,0,1,2};
//        vector<int> nums= {3,1};
//        Solution s;
//        int index = s.search(nums, 1);
//        std::cout << "min " << index << std::endl;
        vector<int> nums = {};
        Solution s;
        int index = s.findMin(nums);
        std::cout << index << std::endl;

    }
}

#endif //ALGORITHM_ROTATESEARCH_H
