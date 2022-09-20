#include <iostream>

const int month = 12;

int main() {
    using namespace std;
    int arr[month];
    int sum = 0;
    for (int i = 0; i < month; i++) {
        cout << "请输入 " << i + 1 << " 月份的销售量：";
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "这一年的销量为：" << sum << endl;
    return 0;
}