#include <iostream>

using namespace std;

int &max(int &, int &);

int main() {
    int num1 = 10;
    int num2 = 20;
    cout << "交换之前：" << num1 << "<->" << num2 << endl;
    swap(num1, num2);
    cout << "交换之后：" << num1 << "<->" << num2 << endl;
    cout << "较大值为：" << max(num1, num2) << endl;
    return 0;
}

int &max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
}