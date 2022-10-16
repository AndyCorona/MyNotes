#ifndef ESSENTIAL_C___02_H
#define ESSENTIAL_C___02_H

#include <iostream>

using std::cout;
using std::endl;

class cd {
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    cd(char *s1, char *s2, int n, double x) {
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        performers = new char[len1 + 1];
        strcpy(performers, s1);
        label = new char[len2 + 1];
        strcpy(label, s2);
        selections = n;
        playtime = x;
    }

    cd(const cd &c) {
        int len1 = strlen(c.performers);
        int len2 = strlen(c.label);
        performers = new char[len1 + 1];
        label = new char[len2 + 1];
        strcpy(performers, c.performers);
        strcpy(label, c.label);
        selections = c.selections;
        playtime = c.playtime;
    }

    cd() {
        cout << "调用基类构造函数" << endl;
        performers = new char[1];
        label = new char[1];
        performers[0] = '\0';
        label[0] = '\0';
        selections = -1;
        playtime = -1.0;
    }

    virtual ~cd() {
        cout << "调用基类析构函数" << endl;
        delete[] performers;
        delete[] label;
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
        delete[] performers;
        delete[] label;
        int len1 = strlen(performers);
        int len2 = strlen(label);
        performers = new char[len1 + 1];
        label = new char[len2 + 1];
        strcpy(performers, c.performers);
        strcpy(label, c.label);
        selections = c.selections;
        playtime = c.playtime;
        return *this;
    }
};

class Classic : public cd {
private:
    char *work;
public:
    Classic() {
        cout << "调用派生类构造函数" << endl;
        work = new char[1];
        work[0] = '\0';
    }

    Classic(const Classic &c) : cd(c) {
        work = new char[strlen(c.work) + 1];
        strcpy(work, c.work);
    }

    Classic(char *s1, char *s2, char *wk, int n, double x) : cd(s1, s2, n, x) {
        int len = strlen(wk);
        work = new char[len + 1];
        strcpy(work, wk);
    }

    virtual ~Classic() {
        cout << "调用派生类析构函数" << endl;
        delete[] work;
    }

    virtual void report() const {
        cd::report();
        cout << "work:" << work << endl;
    }

    Classic &operator=(const Classic &c) {
        if (this == &c) {
            return *this;
        }
        //删除旧的内存空间
        delete[] work;
        //调用基类的赋值运算符将基类部分的成员变量进行赋值
        cd::operator=(c);
        //将派生类中的变量赋值
        int len = strlen(c.work);
        work = new char[len + 1];
        strcpy(work, c.work);
        return *this;
    }
};

#endif //ESSENTIAL_C___02_H
