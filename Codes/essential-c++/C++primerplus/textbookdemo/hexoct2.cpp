#include <iostream>
int main() {
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    //改变 cout 显示整数的方式，改为十六进制
    cout << hex;
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    //改变 cout 显示整数方式，改为八进制
    cout << oct;
    cout << "inseam = " << inseam << " (octal for 42)" << endl;
    return 0;
}