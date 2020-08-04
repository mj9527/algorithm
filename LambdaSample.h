//
// Created by mjzheng on 2020/7/29.
//

#ifndef ALGORITHM_LAMBDASAMPLE_H
#define ALGORITHM_LAMBDASAMPLE_H

#include <iostream>

using namespace std;

class LambdaSample {

};

void TestLambdaSample() {
    int val = 0;
    auto const_val_lamda = [=]() mutable{ val = 4;};
    const_val_lamda();
    std::cout << val << std::endl;

    auto mutable_val_lambda = [&](){val=3;};
    mutable_val_lambda();
    std::cout << val << std::endl;
}


#endif //ALGORITHM_LAMBDASAMPLE_H
