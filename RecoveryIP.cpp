//
// Created by 郑俊明 on 2020/4/18.
//

#include "RecoveryIP.h"
#include <iostream>

void TestIP() {
    string s = "25525511135";
    RecoveryIP recovery;
    vector<string> ipS = recovery.restoreIpAddresses(s);
    for (vector<string>::iterator iter = ipS.begin(); iter != ipS.cend(); iter++) {
        std::cout << *iter << std::endl;
    }
}
