#include <iostream>

int main() {
    using namespace std;

    // n 是 int 类型
    auto n = 10;
    //x 是 double 类型
    auto x = 1.2;

    int auks, hats, coots;
    auks = 19.99 + 11.99;
    //C 版本的强制类型转换
    hats = (int) 19.99 + (int) 11.99;
    //C++版本的强制类型转换
    coots = int(19.99) + int(11.99);
    cout << "auks = " << auks << ", hats = " << hats << ", coots = " << coots << endl;
    char ch = 'Z';
    cout << "The code for " << ch << " is ";
    cout << (int) ch << endl;
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;
    return 0;
}