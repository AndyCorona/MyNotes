#include <iostream>
#include <cctype>

int main() {
    using namespace std;
    int money;
    cout << "请输入税前收入：";
    cin >> money;
    while (money > 0) {
        double tax = 0;
        if (money >= 35000) {
            tax += (money - 35000) * 0.2;
        }

        if (money <= 35000) {
            tax += (money - 15000) * 0.15;
        }

        if (money <= 5000) {
            money -= 5000;
        }
        if (money <= 15000) {
            tax += (money - 5000) * 0.1;
        }


        cout << "所得税为：" << tax << endl;
        cout << "请输入税前收入：";
        cin >> money;
    }
    return 0;
}