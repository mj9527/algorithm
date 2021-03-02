#include <iostream>

#include "RecoveryIP.cpp"
#include "MergeSet.h"
#include "CacheWater.h"
#include "MaxSquare.h"
#include "SubArray.h"
#include "Envelopes.h"
#include "ReverseWord.h"
#include "RotateSearch.h"
#include "KMax.h"

#include "AllOne.h"
#include "MaxIncr.h"
#include "MoveSome.h"
#include "StringMulti.h"
#include "SubString.h"
#include "QuickSort.h"
#include "MaxIsland.h"
#include "ShortPath.h"
#include "BinarySortedTree.h"
#include "Stock.h"
#include "ABSum.h"
#include "VirtualClass.h"
#include "MaxKuahao.h"
#include "Singleton.h"
#include "ZeroEventOdd.h"
#include "RotateMatrix.h"
#include "RemoveElement.h"
#include "LeftAndRight.h"
#include "LambdaSample.h"
#include "PtrSample.h"
#include "SequencePrint.h"
#include "H2O.h"
#include "StringNumber.h"
#include "GroupAnagrams.h"
#include "TwoSum/TwoSum.h"
#include "MyAtoi/MyAtoi.h"
#include "MaxArea/MaxArea.h"
#include "GenerateParenthesis/GenerateParenthesis.h"

void TestArray() {
    int **p = new int*[10];
    for (int i=0; i<10; i++) {
        p[i] = new int[10];
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            p[i][j] = i+j;
        }
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            std::cout << p[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void testSplit(std::string& url) {
    size_t pos = url.find("?");
    if (pos != std::string::npos) {
        std::string path = url.substr(0, pos);
        std::cout << path <<std::endl;
        std::string params = url.substr(pos+1);
        std::cout << params << std::endl;
    }
}

struct MyPoint {
    int x;
    int y;
    MyPoint(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

extern void TestClass();

int main() {
//    std::string url = "http://ac.o2.qq.com/ocpa/ocpa_process/callback?ad_class=2&callback=https%3A%2F%2Fsugar.zhihu.com%2Fplutus_adreaper_callback%3Fsi%3D5848667e-bc6f-4b33-89eb-d4f3dcbea454&callback_type=&channel=10054541&cid=891888&cip=61.240.23.50&click_id=edad24e515eeab812e7b8d24ecbadeec&clk_time=2020-07-09+14%3A43%3A27&cts=1593742723&event=__EVENTTYPE__&idfa=&imei=866654036466727&imei_idfa=866654036466727&imei_idfa_md5=f8b8613ecded578ef1b7821fc7bb395c&is_recurring_user=false&loc_id=21709&m_date=20200709&media_id=22339&mtr_id=&o2_gid=107674&oaid=&oaid_md5=&openid=866654036466727&os=1&sc_id=&sc_name=zhihu_daily&sch_id=9281&source_ip=58.247.212.139&ts=__TIMESTAMP__&value=__EVENTVALUE__&zaid=852120&zcid=891888&zid=105&reg_time=1594278569";
//    testSplit(url);
    //TestIP();
    //TestMerge();
    //TestWater();
    //TestSquare();
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << stoi("025") << std::endl;
    //TestSubArray();
    //TestEnvelopes();
    //TestReverse();
    //TestSearch();
    //TestFindK();

   // TestIncr();

    //TestMoveSome();
    //TestMul();
    //TestUnrepeated();
    //TestSubString();
    //TestQuickSort();
    //TestIsland();

    //TestShortPath();
    //TestSort();
    //TestStock();
    //TestABSum();
    //TestKNum();
    //TestVirtual();
    //TestKuahao();
    //TestSingleton();
    //TestZeroEvenOdd();

    //TestArray();
    //TestMatrix();

   // TestParenthesis();
    //TestRemove();

    //TestLR();
    //TestLambdaSample();
   // StudyPtr();
   // TestAdd();
    // TestSequence();

    //TestH2O();


    //TestClass();

    //TestGroupAnagrams();

//    MyPoint pt = {10, 10};
//
//    MyPoint pt1(20, 20);
//    std::cout << pt.x << pt.y << std::endl;
    TwoSum::testTwoSum();
    MyAtoi::testMyAtoi();
    MaxArea::testMaxArea();
    GenerateParenthesis::TestParenthesis();
    return 0;
}


