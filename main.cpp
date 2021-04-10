#include <iostream>

#include "MergeSet.h"
#include "MaxSquare.h"
#include "Envelopes.h"
#include "ReverseWord.h"
#include "KMax.h"
#include "MaxIncr.h"
#include "MoveSome.h"
#include "QuickSort.h"
#include "MaxIsland.h"
#include "BinarySortedTree.h"
#include "ABSum.h"
#include "MaxKuahao.h"
#include "RotateMatrix.h"
#include "GroupAnagrams.h"
#include "MaxArea/MaxArea.h"
#include "GenerateParenthesis/GenerateParenthesis.h"
#include "RemoveElement/RemoveElement.h"
#include "LongestValidParentheses/LongestValidParentheses.h"
#include "SearchRotate/RotateSearch.h"
#include "RecoveryIP/RecoveryIP.h"
#include "Path/SimplifyPath.h"

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

// 32位机器
struct xx {
    long long x1; // 8
    char x2; // 1
    int x3; // 4
    char x4[2]; // 2
    static int x5;
};

int xx::x5 = 10;

void testInt() {
    int a = 1;
    a += (++a) + (a++);

    int b = ++a; // b=2; a=2;
    int c = a++; c = 2; a=3;
    a += b + c;

    std::cout << a << std::endl;

    xx p;
    std::cout << xx::x5 << std::endl;

}

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
//    TwoSum::testTwoSum();
//    MyAtoi::testMyAtoi();
//    MaxArea::testMaxArea();
//    GenerateParenthesis::TestParenthesis();
    //LongestValidParentheses::testLongestValidParentheses();
    //AddTwoBigNumber::testAddTwoBigNumber();
    //RotateSearch::TestSearch();
    //CppThread::testThread();
    //MultiThread::TestSequence();
    //MultiThread::testFooBar();

    //MultiThread::testZeroEvenOdd();
    //MultiThread::TestH2O();

    //MultiThread::TestFizzBuzz();
    //testInt();

    //RecoveryIP::TestIP();
    //testMin();
    int a = 1;
    TestSimple();
    return 0;
}


