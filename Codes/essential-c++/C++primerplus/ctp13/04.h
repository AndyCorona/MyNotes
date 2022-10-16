#ifndef ESSENTIAL_C___04_H
#define ESSENTIAL_C___04_H

#include <iostream>

using namespace std;

class Port {
private:
    char *brand;
    char style[20];
    int bottles;
public:
    Port(const char *br = "none", const char *st = "none", int b = 0) {
        int len = strlen(br);
        brand = new char[len + 1];
        strcpy(brand, br);
        strcpy(style, st);
        bottles = b;
    }

    Port(const Port &p) {
        int len = strlen(p.brand);
        brand = new char[len + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }

    virtual ~Port() {
        delete[] brand;
    };

    Port &operator=(const Port &p) {
        if (this == &p) {
            return *this;
        }
        delete[] brand;
        int len = strlen(p.brand);
        brand = new char[len + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }

    Port &operator+=(int b) {
        bottles += b;
    }

    Port &operator-=(int b) {
        bottles -= b;
    }

    int BottleCount() const {
        return bottles;
    }

    virtual void Show() const {
        cout << "Brand: " << brand << endl;
        cout << "Kind: " << style << endl;
        cout << "Bottles: " << bottles << endl;
    }

    friend ostream &operator<<(ostream &os, const Port &p) {
        os << p.brand << ", " << p.style << ", " << p.bottles << endl;
        return os;
    }
};

class VintagePort : public Port {
private:
    char *nickname;
    int year;
public:
    VintagePort() {
        Port();
        nickname = "none";
        year = -1;
    }

    VintagePort(const char *br, const char *st, int b, const char *nn, int y) : Port(br, st, b) {
        int len = strlen(nn);
        nickname = new char[len + 1];
        strcpy(nickname, nn);
        year = y;
    }

    VintagePort(const VintagePort &vp) : Port(vp) {
        int len = strlen(vp.nickname);
        nickname = new char[len + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }

    ~VintagePort() {
        delete[] nickname;
    }

    VintagePort &operator=(const VintagePort &vp) {
        if (this == &vp) {
            return *this;
        }
        Port::operator=(vp);
        delete[] nickname;
        int len = strlen(vp.nickname);
        nickname = new char[len + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
        return *this;
    }

    void Show() const {
        Port::Show();
        cout << "nickname: " << nickname << endl;
        cout << "year: " << year << endl;
    }

    friend ostream &operator<<(ostream &os, const VintagePort &vp) {
        cout << (Port) vp;
        os << vp.nickname << ", " << vp.year << endl;
        return os;
    }
};


#endif //ESSENTIAL_C___04_H
