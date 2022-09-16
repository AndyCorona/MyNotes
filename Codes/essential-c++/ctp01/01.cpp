#include <iostream>
#include <string>
#include <complex>

using namespace std;

int main() {
    //赋值初始化
    int num = 10;
    //构造函数初始化，可以给变量同时赋予多个初始值
    complex<int>(0, 7);

    cout << "Please enter your first name and last name:";
    string first_name;
    string last_name;
    cin >> first_name;
    cin >> last_name;
    cout << '\n'
         << "Hello, "
         << first_name
         << last_name
         << " ... and goodbye!\n";
    return 0;
}
