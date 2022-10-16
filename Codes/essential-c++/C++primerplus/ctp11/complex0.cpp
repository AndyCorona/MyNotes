#include <iostream>
#include "complex0.h"

complex operator+(const complex &c1, const complex &c2) {
    complex temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    return temp;
}

complex operator-(const complex &c1, const complex &c2) {
    complex temp;
    temp.real = c1.real - c2.real;
    temp.imaginary = c1.imaginary - c2.imaginary;
    return temp;
}

complex operator*(const complex &c1, const complex &c2) {
    complex temp;
    temp.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    temp.imaginary = c1.real * c2.imaginary - c1.imaginary * c2.real;
    return temp;
}

complex operator*(const complex &c, double n) {
    return n * c;
}

complex operator*(double n, const complex &c) {
    complex temp;
    temp.real = c.real * n;
    temp.imaginary = c.imaginary * n;
    return temp;
}

complex operator~(const complex &c) {
    complex temp;
    temp.imaginary = c.imaginary * -1;
    temp.real = c.real;
    return temp;
}

//重载输入输出函数
std::ostream &operator<<(std::ostream &os, const complex &t) {
    os << "(" << t.real << ", " << t.imaginary << "i)";
    return os;
}

std::istream &operator>>(std::istream &is, complex &t) {
    std::cout << "real: ";
    is >> t.real;
    std::cout << "imaginary: ";
    is >> t.imaginary;
    return is;
}