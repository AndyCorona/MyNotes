#include <iostream>

using namespace std;

//声明函数模版
template<typename T>
void swapp(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

//声明类模版
template<typename T>
class Op {
public:
    T process(T v) {
        return v * v;
    }
};

int main() {
    int a = 10, b = 20;
    cout << "交换之前：a-> " << a << " b-> " << b << endl;
    swapp(a, b);
    cout << "交换之后：a-> " << a << " b-> " << b << endl;
    double x = 15.2, y = 19.6;
    cout << "交换之前：x-> " << x << " y-> " << y << endl;
    swapp(x, y);
    cout << "交换之后：x-> " << x << " y-> " << y << endl;
    string str1 = "hello", str2 = "world";
    cout << "交换之前：str1-> " << str1 << " str2-> " << str2 << endl;
    swapp(str1, str2);
    cout << "交换之后：str1-> " << str1 << " str2-> " << str2 << endl;

    Op<int> opInt;
    Op<double> opDouble;
    cout << "5 * 5 = " << opInt.process(5) << endl;
    cout << "0.5 * 0.5 = " << opDouble.process(0.5) << endl;


    return 0;
}