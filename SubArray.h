//
// Created by 郑俊明 on 2020/4/19.
//

#ifndef ALGORITHM_SUBARRAY_H
#define ALGORITHM_SUBARRAY_H

//输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#include <vector>
#include <iostream>

using namespace std;


class SubArray {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sum = nums[0];
        int current = sum;
        int len = nums.size();
        for (int i=1; i<len; i++) {
            if (current >= 0) {
                current += nums[i];
            } else {
                current = nums[i];
            }
            if (current > sum) {
                sum = current;
            }
        }
        return sum;


//        int current=nums[0];
//        int sum=nums[0];
//
//        int len = nums.size();
//        for (int i=1; i<len; i++) {
//            if(current<0)current=nums[i];//当前数小于0 肯定会舍去（否则将会影响接下来的和），换为下一个数
//            else current+=nums[i];//如果当前数不小于0，那么他会对接下来的和有积极影响
//            if(current>sum) {
//                sum = current;//这里既实现了负数返回最大也实现了扫描法
//            }
//            std::cout << nums[i] << " " << current << " "  << sum << std::endl;
//        }
//        return sum;
//        int sum=nums[0];
//        int current=nums[0];
//        int len = nums.size();
//        for(int i=1;i<len;i++) {
//            if(current>0)current+=nums[i];
//            else current=nums[i];
//            if(sum<current)sum=current;
//        }
//        return sum;

    }


    int maxSub(vector<int>& nums, int len) { // get one element max sum
        if (len == 1) {
            return nums[0];
        }
        int lastElement = nums[len-1];
        int beforeSum = maxSub(nums, len-1);
        if (beforeSum >= 0) {
            return beforeSum + lastElement;
        } else {
            return lastElement;
        }
    }
};

void TestSubArray() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    SubArray sub;
    int sum = sub.maxSubArray(nums);
    std::cout << sum << std::endl;
}


#endif //ALGORITHM_SUBARRAY_H
