#include <iostream>

using namespace std;

//变量声明
extern int a, b;
extern int c;
extern float f;

int main() {
    //强制类型转换
    int temp_a = 10;
    long long_temp = (long) temp_a;
    short int temp_short_int = (short) temp_a;

    //变量定义
    int a, b;
    int c;
    float f;

    //初始化
    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;

    f = 70.0 / 3.0;
    cout << f << endl;

    return 0;
}
