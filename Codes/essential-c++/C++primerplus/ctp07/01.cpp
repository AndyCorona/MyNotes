#include <iostream>

double fun(int num1, int num2);

int main() {
    using namespace std;
    int num1;
    int num2;
    cout << "请输入两个数字：\n";
    while (cin >> num1 && cin >> num2) {
        if (num1 == 0 || num2 == 0) {
            break;
        }
        double result = fun(num1, num2);
        cout << "调和平均数为：" << result << endl;
        cout << "请输入两个数字：\n";
        cin >> num1 >> num2;
    }
    cout << "程序结束\n";
    return 0;
}

double fun(int num1, int num2) {
    return 2.0 * (num1 * num2) / (num1 + num2);
}