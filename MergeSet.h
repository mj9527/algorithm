//
// Created by 郑俊明 on 2020/4/19.
//

#ifndef ALGORITHM_MERGESET_H
#define ALGORITHM_MERGESET_H

#include <vector>
#include <algorithm>

using namespace std;

void PrintResult(vector<vector<int>>& result) {
    vector<vector<int>>::iterator iter = result.begin();
    for (; iter != result.end(); iter++) {
        for (vector<int>::iterator e = iter->begin(); e != iter->end(); e++) {
            std::cout << *e << " ";
        }
        std::cout << std::endl;
    }
}

class MergeSet {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//直接排序即可
        PrintResult(intervals);
        vector<vector<int>>res;
        for(int i = 0;i<intervals.size();i++)
        {
            if(res.empty()||intervals[i][0] > res.back()[1])//如果res为空或者i位置的区间与上个区间不能合并
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(intervals[i][1],res.back()[1]);//与上个区间能合并，因为res.back()返回的是引用，因此可以直接改。
            }
        }
        return res;
    }
};



void TestMerge() {
    vector<vector<int>> intervals = {{1,7}, {2,6}, {8,20}, {15,18}};
    MergeSet m;
    vector<vector<int>> result = m.merge(intervals);

    PrintResult(result);
}




#endif //ALGORITHM_MERGESET_H
