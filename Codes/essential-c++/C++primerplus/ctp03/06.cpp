#include <iostream>

using namespace std;

int main() {
    int mile;
    cout << "请输入行驶里程数（公里）：";
    cin >> mile;
    int consume;
    cout << "请输入耗油量（升）：";
    cin >> consume;
    cout << "每公里耗油量为：" << consume * 1.0 / mile << endl;
    return 0;
}