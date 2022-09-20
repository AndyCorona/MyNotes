#include <iostream>

const int month = 12;

int main() {
    using namespace std;
    int arr[3][month];
    int total = 0;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < month; j++ ){
            cout << "请输入 " << j + 1 << " 月份的销售量：";
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        cout << "第 " << i + 1 << " 年的销量为：" << sum << endl;
        total += sum;
    }
    cout << "三年的总销量为：" << total << endl;
    return 0;
}