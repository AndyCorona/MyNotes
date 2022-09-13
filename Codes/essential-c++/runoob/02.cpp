#include <iostream>

using namespace std;

enum color {
    //0，默认的枚举常量值
    red,
    //5，自定义枚举常量值
    green = 5,
    //6，从上一个枚举值延续
    blue
} variable;



enum time {
    morning,
    noon,
    afternoon
};

int main() {
    //PART I variable 是一个 color 类型的枚举变量
    variable = blue;
    cout << "the default enum value: " << variable << endl;
    variable = green;
    cout << "the user-defined enum value: " << variable << endl;
    variable = red;
    cout << "the default enum value: " << variable << endl;

    //PART II  datetime 是一个 time 类型的枚举变量
    enum time datetime;
    for (int time = morning; time <= afternoon; time++) {
        cout << "now is " << time << endl;
    }
    return 0;
}






