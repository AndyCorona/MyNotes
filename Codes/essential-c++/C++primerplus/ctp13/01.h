#ifndef ESSENTIAL_C___01_H
#define ESSENTIAL_C___01_H

#include <iostream>

using std::cout;
using std::endl;

class cd {
private:
    char performers[50];
    char label[50];
    int selections;
    double playtime;
public:
    cd(char *s1, char *s2, int n, double x) {
        strncpy(performers, s1, 50);
        strncpy(label, s2, 50);
        selections = n;
        playtime = x;
    }

//    cd(const cd &c) {
//        strncpy(performers, c.performers, 50);
//        strncpy(label, c.label, 50);
//        selections = c.selections;
//        playtime = c.playtime;
//    }

    cd() {
        cout << "调用基类构造函数" << endl;
    }

    virtual ~cd() {
        cout << "调用基类析构函数" << endl;
    }

    virtual void report() const {
        cout << "performer:" << performers << endl;
        cout << "label: " << label << endl;
        cout << "selections: " << selections << endl;
        cout << "playtime: " << playtime << endl;
    }

    cd &operator=(const cd &c) {
        if (this == &c) {
            return *this;
        }
        strncpy(performers, c.performers, 50);
        strncpy(label, c.label, 50);
        selections = c.selections;
        playtime = c.playtime;
        return *this;
    }
};

class Classic : public cd {
private:
    char work[50];
public:
    Classic() {
        cout << "调用派生类构造函数" << endl;
    }

//    Classic(const Classic &c) : cd(c) {
//        strncpy(work, c.work, 50);
//    }


    Classic(char *s1, char *s2, char *wk, int n, double x) : cd(s1, s2, n, x) {
        strncpy(work, wk, 50);
    }


    virtual ~Classic() {
        cout << "调用派生类析构函数" << endl;
    }

    virtual void report() const {
        cd::report();
        cout << "work:" << work << endl;
    }

    Classic &operator=(const Classic &c) {
        if (this == &c) {
            return *this;
        }
        //调用基类的赋值运算符将基类部分的成员变量进行赋值
        cd::operator=(c);
        //将派生类中的变量赋值
        strncpy(work, c.work, 50);
        return *this;
    }
};


#endif //01_H
