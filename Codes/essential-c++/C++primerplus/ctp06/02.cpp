#include <iostream>
const int ArSize  = 10;

int main() {
    using namespace std;
    double arr[ArSize];
    cout << "请输入数字：";
    int i = 0;
    int sum = 0;
    while((cin >> arr[i]) && i <= ArSize) {
        sum += arr[i++];
        cout << "请输入数字：";
    }
    int average = sum / i;
    cout << "平均值为：" << average << endl;
    int count = 0;
    for (int j = 0 ; j < i; j++) {
        if (arr[j] > average) {
            count ++;
        }
    }
    cout << "大于平均值有 " << count << " 个" << endl;
    return 0;

}