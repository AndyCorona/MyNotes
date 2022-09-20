#include <iostream>

int main() {
    using namespace std;
    cout << "请输入一个数字（输入 0 代表结束）：";
    int num;
    cin >> num;
    int sum = 0;
    while (num != 0) {
        sum += num;
        cout << "累计和为：" << sum << endl;
        cin >> num;
    }
    return 0;
}