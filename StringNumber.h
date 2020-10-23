//
// Created by mjzheng on 2020/8/5.
//

#ifndef ALGORITHM_STRINGNUMBER_H
#define ALGORITHM_STRINGNUMBER_H


class StringNumber {
public:
    StringNumber();
    StringNumber(int i) {}
    StringNumber(const StringNumber& other) {
        std::cout << "copy" << std::endl;
    }
    StringNumber& operator=(const StringNumber& other) {
        std::cout << "=" << std::endl;
    }

    void operator[](int index) {
        std::cout << "index" << std::endl;
    }

    void* operator new(size_t size);

    void operator delete(void* p);
};


#endif //ALGORITHM_STRINGNUMBER_H
