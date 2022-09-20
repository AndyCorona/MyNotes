#include <iostream>

using namespace std;

int main() {
    int min_value;
    int max_value;
    cout << "请输入一个整数：";
    cin >> min_value;
    cout << "请输入另一个整数：";
    cin >> max_value;
    int sum = 0;
    for (int i = min_value; i <= max_value ;++i) {
        sum += i;
    }
    cout << "最后求和为：" << sum << endl;
    return 0;
}