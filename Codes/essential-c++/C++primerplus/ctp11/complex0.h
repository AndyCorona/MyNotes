#ifndef COMPLEX0_H
#define COMPLEX0_H

class complex {
private:
    double real;
    double imaginary;
public:
    complex(double real = 0.0, double imaginary = 0.0) {
        this->real = real;
        this->imaginary = imaginary;
    };

    ~complex(){};

    friend complex operator+(const complex &c1, const complex &c2);

    friend complex operator-(const complex &c1, const complex &c2);

    friend complex operator*(const complex &c1, const complex &c2);

    friend complex operator*(const complex &c, double n);

    friend complex operator*(double n, const complex &c);

    friend complex operator~(const complex &c);

    friend std::ostream &operator<<(std::ostream &os, const complex &t);

    friend std::istream &operator>>(std::istream &is, complex &t);
};

#endif //COMPLEX0_H
