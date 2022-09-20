#include <iostream>

using namespace std;

double add(double, double);

double divide(double, double);

double minu(double, double);

double multi(double, double);

void calculate(double, double, double (*pt[4])(double, double));

int main() {
    cout << "请输入两个数字：";
    double num1;
    double num2;
    double (*pt[4])(double, double);
    double (*add_ptr)(double, double) = add;
    double (*minu_ptr)(double, double) = minu;
    double (*divide_ptr)(double, double) = divide;
    double (*multi_ptr)(double, double) = multi;
    pt[0] = add_ptr;
    pt[1] = minu_ptr;
    pt[2] = divide_ptr;
    pt[3] = multi_ptr;
    while (cin >> num1 && cin >> num2) {
        calculate(num1, num2, pt);
    }
    return 0;
}

double add(double x, double y) {
    return x + y;
}

double divide(double x, double y) {
    return x / y;
}

double minu(double x, double y) {
    return x - y;
}

double multi(double x, double y) {
    return x * y;
}

void calculate(double d1, double d2, double (*pt[4])(double, double)) {
    for (int i = 0; i < 4; i++) {
        cout << "调用第 " << i + 1<< " 个函数，结果为：" <<  pt[i](d1, d2) << endl;
    }
}