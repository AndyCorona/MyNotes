#include <iostream>

using namespace std;

int main() {
    cout << "请输入身高（米）：";
    double height;
    cin >> height;
    cout << "请输入体重（千克）：";
    double weight;
    cin >> weight;

    cout << "BMI 为：" << weight / (height * height) << endl;
    return 0;
}