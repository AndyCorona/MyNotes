#ifndef STRING2_H
#define STRING2_H

#include <iostream>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;

class String {

private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String();

    String(const char *s);

    String(const String &s);

    ~String();

    int length() const {
        return len;
    };

    String &operator=(const String &s);

    String &operator=(const char *c);

    char &operator[](int i);

    char &operator[](int i) const;

    String &stringlow(void);

    String &stringup(void);

    int has(const char c) const;

    friend bool operator<(const String &s1, const String &s2);

    friend bool operator>(const String &s1, const String &s2);

    friend bool operator==(const String &s1, const String &s2);

    friend ostream &operator<<(ostream &os, const String &st);

    friend istream &operator>>(istream &is, String &st);

    friend String operator+(const String &s1, const String &s2);

    friend String operator+(const String &s1, const char *c);

    friend String operator+(const char *c, const String &s1);

    static int HowMany();
};

#endif //STRING2_H
