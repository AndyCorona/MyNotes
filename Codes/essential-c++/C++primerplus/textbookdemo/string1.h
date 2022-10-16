#ifndef STRING1_H
#define STRING1_H

#include <iostream>

using std::ostream;
using std::istream;

class String {
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    //默认构造器
    String();

    //有参构造器
    String(const char *s);

    //析构函数
    ~String();

    //复制构造器
    String(const String &);

    int length() const {
        return this->len;
    }

    //重载运算符
    String &operator=(const String &);

    String &operator=(const char *);

    char &operator[](int i);

    const char &operator[](int i) const;

    //重载友元函数
    friend bool operator<(const String &s1, const String &s2);

    friend bool operator>(const String &s1, const String &s2);

    friend bool operator==(const String &s1, const String &s2);

    friend ostream &operator<<(ostream &os, const String &st);

    friend istream &operator>>(istream &is, String &st);

    //静态函数
    static int HowMany();
};

#endif //STRING1_H
