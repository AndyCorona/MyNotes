#include <iostream>

//模版函数
template<class T>
T lesser(T a, T b) {
    return a < b ? a : b;
}

//正常函数
int lesser(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;

}

int main() {
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;
    //调用争正常函数
    cout << lesser(m, n) << endl;
    //调用带有 double 类型的模版函数
    cout << lesser(x, y) << endl;
    //调用带有 int 类型的模版函数
    cout << lesser<>(m, n) << endl;
    //调用带有 int 类型的模版函数
    cout << lesser<int>(x, y) << endl;
    return 0;

}