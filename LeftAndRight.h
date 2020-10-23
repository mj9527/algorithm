//
// Created by mjzheng on 2020/7/27.
//

#ifndef ALGORITHM_LEFTANDRIGHT_H
#define ALGORITHM_LEFTANDRIGHT_H

class MyString {
private:
    char* _data;
    size_t   _len;
    void _init_data(const char *s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
public:
    MyString() {
        _data = NULL;
        _len = 0;
        std::cout << "normal constructor" << std::endl;
    }

    MyString(const char* p) {
        _len = strlen (p);
        _init_data(p);
        std::cout << "copy normal constructor " << std::string(p) << std::endl;
    }

    MyString(const MyString& str) {
        _len = str._len;
        _init_data(str._data);
        std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
    }

    MyString& operator=(const MyString& str) {
        if (this != &str) {
            _len = str._len;
            _init_data(str._data);
        }
        std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
        return *this;
    }

    virtual ~MyString() {
        if (_data) free(_data);
    }

    MyString(MyString&& str) {
        std::cout << "Move Constructor is called! source: " << str._data << std::endl;
        _len = str._len;
        _data = str._data;
        str._len = 0;
        str._data = NULL;
    }

    MyString& operator=(MyString&& str) {
        std::cout << "Move Assignment is called! source: " << str._data << std::endl;
        if (this != &str) {
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = NULL;
        }
        return *this;
    }
};


class LeftAndRight {
public:
    LeftAndRight(MyString&& name, MyString&& sex)
    : m_name(name), m_sex(sex)
    {
        std::cout << "right copy" << std::endl;
    }

    LeftAndRight(MyString& name, MyString& sex)
            : m_name(name), m_sex(sex)
    {
        std::cout << "left copy " << __func__ << std::endl;
    }

private:
    MyString& m_name;
    MyString& m_sex;
};

void PrintInt( int& i) {
    std::cout << __func__  << std::endl;
    std::cout << i << std::endl;
}

void PrintInt(int&&i) {
    std::cout << __func__  << std::endl;
    std::cout << "right     " << i << std::endl;
}

void process_value(int& i)
{
    std::cout << "LValue processed: " << i << std::endl;

    i++;
}

void process_value(int&& i)
{
    std::cout << "RValue processed: " << i << std::endl;
    process_value(i);
//    i = 10;
//    std::cout << "modify " << i << std::endl;
}

void TestLR() {
//    PrintInt(1);
//    MyString name("mj");
//    MyString sex("sex");
//    LeftAndRight a(name, sex);

    int a = 0;
    process_value(a);

    process_value(1);

//    int&& b = 10;
//    process_value(b);
//    std::cout << "out " << b << std::endl;
//
//    int c = 10;
//    process_value(c);
//    std::cout << "out " << c << std::endl;
}




#endif //ALGORITHM_LEFTANDRIGHT_H
