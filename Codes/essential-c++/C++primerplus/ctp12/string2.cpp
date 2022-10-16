#include <cstring>
#include "string2.h"
#include <ctype.h>

using std::cout;
using std::cin;


int String::num_strings = 0;

int String::HowMany() {
    return num_strings;
}

String::String(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    num_strings++;
}

String::~String() {
    --num_strings;
    delete[] str;
}

String &String::operator=(const String &s) {
    if (this == &s) {
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

String &String::operator=(const char *c) {
    delete[] str;
    len = strlen(c);
    str = new char[len + 1];
    strcpy(str, c);
    return *this;
}

char &String::operator[](int i) {
    return str[i];
}

char &String::operator[](int i) const {
    return str[i];
}

bool operator<(const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str);
}

bool operator>(const String &s1, const String &s2) {
    return s2 < s1;
}

bool operator==(const String &s1, const String &s2) {
    return strcmp(s1.str, s2.str) == 0;
}

ostream &operator<<(ostream &os, const String &s) {
    os << s.str;
    return os;
}

istream &operator>>(istream &is, String &s) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        s = temp;
        s.len = strlen(s.str);
    }
    while (is && (is.get() != '\n')) {
        continue;
    }
    return is;
}

String operator+(const String &s1, const String &s2) {
    String temp;
    //获取两个字符串总长度
    int len = s1.len + s2.len;
    temp.len = len;
    //动态分配新的内存空间，以存放两个字符串总和
    temp.str = new char[len + 1];
    //分别将两个字符串复制到新的内存空间中
    strcpy(temp.str, s1.str);
    strcpy(temp.str + s1.len, s2.str);
    return temp;
}

String operator+(const String &s1, const char *c) {
    String temp;
    int len = s1.len + strlen(c);
    temp.len = len;
    temp.str = new char[len + 1];
    strcpy(temp.str, s1.str);
    strcpy(temp.str + s1.len, c);
    return temp;
}

String operator+(const char *c, const String &s1) {
    String temp;
    int len = s1.len + strlen(c);
    temp.len = len;
    temp.str = new char[len + 1];
    strcpy(temp.str, c);
    strcpy(temp.str + strlen(c), s1.str);
    return temp;
}

String &String::stringlow() {
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return *this;
}

String &String::stringup(void) {
    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
    return *this;
}


int String::has(const char c) const {
    int len = 0;
    for (int i = 0; i < this->len; i++) {
        if (c == str[i]) {
            len++;
        }
    }
    return len;
}

