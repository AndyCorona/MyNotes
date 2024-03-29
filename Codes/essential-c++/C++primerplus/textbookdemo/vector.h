#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace VECTOR {
    class Vector {
    public:
        //两种模式切换
        enum Mode {
            RECT, POL
        };
    private:
        //私有成员变量
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;

        //私有成员方法
        void set_mag();

        void set_ang();

        void set_x();

        void set_y();

    public:
        Vector();

        Vector(double n1, double n2, Mode form = RECT);

        void reset(double n1, double n2, Mode form = RECT);

        ~Vector();

        double xval() const { return x; }

        double yval() const { return y; }

        double magval() const { return mag; }

        double angval() const { return ang; }

        void polar_mode();

        void rect_mode();

        //运算符重载
        Vector operator+(const Vector &b) const;

        Vector operator-(const Vector &b) const;

        Vector operator-() const;

        Vector operator*(double n) const;

        //友元函数
        friend Vector operator*(double n, const Vector &a);

        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
}

#endif //VECTOR_H
