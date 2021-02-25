//
// Created by mjzheng on 2021/2/24.
//

#ifndef ALGORITHM_THREESUM_H
#define ALGORITHM_THREESUM_H

namespace ThreeSum {
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort( nums.begin(), nums.end());
            vector<vector<int>> res;

            if( nums.size() < 3 || nums[0] > 0 || nums[ nums.size() - 1] < 0)
                return res;

            for( int i = 0; i < nums.size(); i++){
                if( nums[i] > 0)
                    break;

                if( i > 0 && nums[i] == nums[i-1])
                    continue;

                int l = i + 1, r = nums.size() - 1;
                while( l < r){
                    if( nums[i] + nums[l] + nums[r] == 0){
                        vector<int> temp = { nums[i] , nums[l] , nums[r]};
                        res.push_back( temp);

                        //去重
                        while( l<r && nums[l]==nums[l+1])l++;
                        while( l<r && nums[r]==nums[r-1])r--;

                        l++;
                        r--;
                    }
                    else if( nums[i] + nums[l] + nums[r] > 0)
                        r--;
                    else if( nums[i] + nums[l] + nums[r] < 0)
                        l++;
                }
            }

            return res;
        }
    };
}

#endif //ALGORITHM_THREESUM_H
