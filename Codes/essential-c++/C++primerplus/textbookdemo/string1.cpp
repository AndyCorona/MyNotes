#include <iostream>
#include "string1.h"

using std::cout;
using std::cin;


//初始化静态变量
int String::num_strings = 0;

int String::HowMany() {
    return num_strings;
}

String::String(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String() {
    int len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st) {

    num_strings++;
    int len = st.length();
    str = new char[len + 1];
    std::strcpy(str, st.str);
}


String::~String() {
    delete[] str;
    num_strings--;
}

//重载赋值运算符
String &String::operator=(const String &st) {
    //不能给自己赋值
    if (this == &st) {
        return *this;
    }
    //删除原先字符串分配的内存空间
    delete[] str;
    //重新分配
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}


String &String::operator=(const char *s) {
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &String::operator[](int i) {
    return str[i];
}

const char &String::operator[](int i) const {
    return str[i];
}


bool operator<(const String &s1, const String &s2) {
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String &s1, const String &s2) {
    return s2 < s1;
}

bool operator==(const String &s1, const String &s2) {
    return (std::strcmp(s1.str, s2.str) == 0);
}

//重载输入输出函数
ostream &operator<<(ostream &os, const String &st) {
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        st = temp;
    }
    while (is && (is.get() != '\n')) {
        continue;
    }
    return is;
}






