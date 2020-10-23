//
// Created by mjzheng on 2020/8/5.
//
#include <iostream>
#include <new>
#include <cstdlib>
#include "StringNumber.h"

StringNumber::StringNumber() {
    std::cout << "constructor" << std::endl;
}

void* StringNumber::operator new(size_t size)
{
    std::cout << "new use" << std::endl;
    void* p = malloc(size);
    return p;
}

void StringNumber::operator delete(void* p)
{
    free(p);
    std::cout << "delete" << std::endl;
}

void TestClass() {
    StringNumber* p = new StringNumber();
    delete p;
}
